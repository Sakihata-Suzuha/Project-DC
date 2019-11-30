#include "./network_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../def.h"
#include "../module/easylogging++.h"

int registerListenSocket()
{
	int retFd;
	int ret;
	struct sockaddr_in addr;

	retFd = socket(AF_INET,SOCK_STREAM,0);
	if(retFd == -1){
		perror("[socket]");
		LOG(ERROR) << "socket register failed...\n";

		return _SOCKET_REGISTER_ERROR_;
	}

	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(777);

	ret = bind(retFd,(struct sockaddr*)&addr,sizeof(addr));
	if(ret == -1){
		perror("[bind]");
		LOG(ERROR) << "socket bind failed...\n";

		return _SOCKET_BIND_ERROR_; 
	}

	ret = listen(retFd,_SOCKET_LISTEN_SIZE_);
	if(ret == -1){
		perror("[listen]");
		LOG(ERROR) << "socket listen failed...\n";

		return _SOCKET_LISTEN_ERROR_;
	}

	return retFd;
}
