#include <stdio.h>
#include <sys/epoll.h>
#include "initEpoll.h"

int initEpoll(int* epfd, struct epoll_event* ev, int* lfd)
{
		//todo 判空指针
		
		int ret;

		*epfd = epoll_create(1);

		ev->events = EPOLLIN|EPOLLERR;
		ev->data.fd = *lfd;

		ret = epoll_ctl(*epfd,EPOLL_CTL_ADD,*lfd,ev);
		if(ret < 0){
			perror("[epoll_ctl]");
		}

		printf("%s succ...\n",__func__);

		return 0;
}
