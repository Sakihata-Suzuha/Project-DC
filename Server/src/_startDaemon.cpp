#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "./Process_Manager/myFork.h"
#include "./Network_Manager/regSocket.h"
#include "./Network_Manager/initEpoll.h"
#include "easylogging++.h"

int _startDaemon()
{
		int ret;
		pid_t pid;
		pid_t sid;
		int fd;
		int i = 8;

		pid = myFork();
		if(pid == 0){
				sid = setsid();
				if(sid < 0){
						perror("[setsid]");
						goto err1;
				}
				else if(sid > 0){
						ret = chdir("../.");
						if(ret < 0){
								perror("[chdir]");
								goto err2;
						}
						else if(ret == 0){
								umask(0002);

								fd = open("./log/aaaa.test",O_APPEND|O_CREAT|O_RDWR);
								if(fd < 0){
										perror("[open]");
										goto err3;
								}

								dup2(fd,STDIN_FILENO);
								dup2(fd,STDOUT_FILENO);
								dup2(fd,STDERR_FILENO);

								printf("%s succ\n",__func__);
								printf("task start run...\n");
								
								int lfd;
								struct sockaddr_in addr;

								int epfd;
								struct epoll_event ev;
								struct epoll_event cev[1024];

								regSocket(&lfd);
								initEpoll(&epfd,&ev,&lfd);

								while(i)
								{
									//	sleep(2);
									//	printf("%d\n",i--);
									
									//printf("epoll start working...\n");	
									
									int evfds = epoll_wait(epfd,cev,1024,2048);
									if(evfds < 0){
										printf("epoll_wait err...\n");
									}
									else if(evfds == 0){
										//printf("epoll_wait no have link...\n");
									}
									else if(evfds > 0){
										printf("epoll_wait active fd is %d...\n",evfds);
									}

									for(int i = 0; i < evfds; ++i)
									{
											struct epoll_event& activeEvent = cev[i];

											if(activeEvent.data.fd == lfd){
													printf("new client...\n");

													bzero(&addr,sizeof(addr));
													socklen_t sklen = sizeof(addr);

													int afd = accept(lfd,(sockaddr*)&addr,&sklen);

													char* ip = inet_ntoa(addr.sin_addr);
													printf("[ip]%s\n",ip);

													epoll_event tEv;
													tEv.data.fd = afd;
													tEv.events = EPOLLIN|EPOLLERR|EPOLLRDHUP; 
													//后续改边沿模式
													//tEv.events = EPOLLIN|EPOLLET;
													
													epoll_ctl(epfd,EPOLL_CTL_ADD,afd,&tEv);
											}
											else if(activeEvent.events & EPOLLIN)
											{
													printf("EPOLLIN event...\n");

													char buf[1024] = "";
													
													int ret = read(activeEvent.data.fd,buf,sizeof(buf)-1);
													if(ret < 0){
															perror("[read]");
													}

													printf("[recv]%s\n",buf);

													send(activeEvent.data.fd,"周阳露牛逼\n\0",sizeof("周阳露牛逼\n\0"),0);
													send(activeEvent.data.fd,buf,sizeof(buf)-1,0);
													
													printf("http???\n");
											}
											else if(activeEvent.events & EPOLLERR || activeEvent.events & EPOLLRDHUP)
											{
												LOG(INFO) << "client close , because of err\n";
												epoll_ctl(epfd,EPOLL_CTL_DEL,activeEvent.data.fd,NULL);
												close(activeEvent.data.fd);
												continue;
											}
									}
								}

								printf("daemon go away...\n");
								exit(0);
						}
				}
		}
		else if(pid > 0){
				goto pExit;
		}

err3:
		return -3;
err2:
		return -2;
err1:
		return -1;
pExit:
		return 0;
}
