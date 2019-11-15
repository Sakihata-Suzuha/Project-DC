#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "regSocket.h"

int regSocket(int* lisfd)
{
		//todo 判空指针

		struct sockaddr_in laddr;

		bzero(&laddr,sizeof(laddr));
		
		*lisfd = socket(AF_INET,SOCK_STREAM,0);

		laddr.sin_family = AF_INET;
		laddr.sin_addr.s_addr = htons(INADDR_ANY);
		laddr.sin_port = htons(777);

		bind(*lisfd,(struct sockaddr*)&laddr,sizeof(laddr));
		listen(*lisfd,1024);

		printf("regSocket succ...\n");

		return 0;
}
