#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include "./resrc_init/resrc_init.h"
#include "./Log_Module/easylogging++.h"
#include "./Process_Manager/Process_Manager.h"
#include "./Network_Manager/Network_Manager.h"
#include "./def.h"

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
				ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET;

				ret = epoll_ctl(epfd,EPOLL_CTL_ADD,afd,&ev);
				if(ret == -1){
					LOG(ERROR) << "afd add epolltree failed...\n";
				}
			}
			else if(active.events & EPOLLRDHUP || active.events & EPOLLERR){
				LOG(INFO) << "client abnormal exit...\n";

				epoll_ctl(epfd,EPOLL_CTL_DEL,active.data.fd,&active);
				close(active.data.fd);
			}
			else if(active.events & EPOLLIN){
				char buf[BUFSIZ] = "";
				ret = recv(active.data.fd,buf,sizeof(buf),0);
				if(ret == -1){
					perror("[recv]");
					LOG(WARNING) << "recv data error!!!\n";

					continue;
				}
				else if(ret == 0){
					LOG(INFO) << "recv data is 0 byte?\n";
				}

				printf("recv: %s\n",buf);
				// test head
				string str("copy that: ");
				string wtf(buf);
				str += wtf;
				LOG(DEBUG) << wtf<< "\n";
				ret = send(active.data.fd,str.c_str(),sizeof(str.c_str()),MSG_NOSIGNAL);
				// test end
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
