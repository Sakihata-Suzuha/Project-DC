#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <iostream>
#include "./module/easylogging++.h"
#include "./process_manager/process_manager.h"
#include "./network_manager/network_manager.h"
#include "./def.h"
#include "./resource_init/resource_init.h"
#include "./pthread_manager/pthread_manager.h"

using namespace std;
using namespace el;

void core(void* data)
{
	int ret;

	int lfd;
	int epfd;
	epoll_event rootEvent;

	sockaddr_in clientAddr;
	int evfds;
	epoll_event events[_EPOLL_EVENT_SIZE_];

	lfd = registerListenSocket();
	if(lfd < 0){
		LOG(ERROR) << "registerListenSocket error!!!\n";

		exit(_SOCKET_LISTEN_ERROR_);
	}

	epfd = epoll_create(1);
	if(epfd == -1){
		perror("[epoll_create]");
		LOG(ERROR) << "epoll create error!!!\n";

		exit(_EPOLL_CREATE_ERROR_);
	}

	rootEvent.events = EPOLLIN;
	rootEvent.data.fd = lfd;

	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&rootEvent);
	if(ret == -1){
		LOG(ERROR) << "epfd add epolltree failed...\n";

		exit(_EPOLL_CTL_ERROR_);
	}

	LOG(INFO) << "-------- init epoll successed --------\n";

	for(;;){
		evfds = epoll_wait(epfd,events,_EPOLL_EVENT_SIZE_,1024);
		if(evfds == -1){
			LOG(ERROR) << "epoll wait error!!!\n";

			exit(_EPOLL_WAIT_ERROR_);
		}

		for(int i = 0; i < evfds; ++i)
		{
			epoll_event& active = events[i];
			if(active.data.fd == lfd){
				LOG(INFO) << "new connect...";

				bzero(&clientAddr,sizeof(clientAddr));
				socklen_t socklen = sizeof(clientAddr);
				int afd = accept(lfd,(sockaddr*)&clientAddr,&socklen);

				char*	   ip = inet_ntoa(clientAddr.sin_addr);
				uint16_t port = ntohs(clientAddr.sin_port);
				LOG(INFO) << ">>" << ip << ":" << port << "<<\n";

				epoll_event ev;
				ev.data.fd = afd;
				ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET|EPOLLONESHOT;

				int flag = fcntl(ev.data.fd,F_GETFL);
				flag |= O_NONBLOCK;
				fcntl(ev.data.fd,F_SETFL,flag);

				ret = epoll_ctl(epfd,EPOLL_CTL_ADD,afd,&ev);
				if(ret == -1){
					LOG(ERROR) << "afd add epolltree failed...\n";
				}

				char buf[] = "hello...\n";
				ret = send(ev.data.fd,buf,sizeof(buf),MSG_NOSIGNAL);
				if(ret == -1){
					perror("[send]");
					LOG(ERROR) << "send data error!!!\n";
				}

				LOG(INFO) << "add new connect succ...\n";
			}
			else if(active.events & EPOLLRDHUP || active.events & EPOLLERR){
				LOG(INFO) << "client abnormal exit...\n";

				epoll_ctl(epfd,EPOLL_CTL_DEL,active.data.fd,&active);
				close(active.data.fd);
			}
			else if(active.events & EPOLLIN){
				taskArg arg;
				arg.iRootEpfd = epfd;
				arg.iActiveFd = active.data.fd;
				epollin_task(&arg);
			}
			else {
				LOG(WARNING) << "_UNKNOWN_EVENT_!!!!!!\n";
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int ret;

	ret = logInit();
	
	ret = __StartDaemon(core);
	if(ret < 0){
		printf("init daemon error!!!\n");
		LOG(FATAL) << "init daemon error!!!\n";
	}
}
