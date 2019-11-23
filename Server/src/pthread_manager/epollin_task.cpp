#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <iostream>
#include <string>
#include <thread>
#include "./pthread_manager.h"
#include "../module/easylogging++.h"
#include "../def.h"

void* startRoutine_epollTask(void* arg)
{
	// test begin
	taskArg data = *((taskArg*)arg);
	pthread_t ppid = pthread_self();
	//	char buf[_BUFFER_SIZE_];
	char buf[4];
	std::string str = ">";
	int ret;

	memset(buf,'\0',sizeof(buf));

	LOG(DEBUG) << ppid << " start task operation...\n";

	for(;;){
		ret = recv(data.iActiveFd,buf,sizeof(buf)-1,0);
		if(ret < 0){
			if(errno == EAGAIN){
				LOG(DEBUG) << "EAGAIN\n";

				//一通操作没卵用？
				//依旧单线程顺序读取
				epoll_event event;
				event.data.fd = data.iActiveFd;
				event.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET|EPOLLONESHOT;
				ret = epoll_ctl(data.iRootEpfd,EPOLL_CTL_MOD,data.iActiveFd,&event);
				if(ret == -1){
					LOG(ERROR) << "epoll_ctl error!!!";
				}
				else{
					LOG(ERROR) << "epoll_ctl succ???";
				}
				//end

				break;
			}
			else{
				perror("[recv]");
				LOG(ERROR) << "recv error!!!\n";
			}
		}
		else if(ret == 0){
			LOG(INFO) << "peer has performed an orderly shutdown...\n";

			break;
		}
		else if(ret > 0){
			//buf[ret] = '\0';
			LOG(DEBUG) << "recv get: " << buf << "\n";
			str = str + buf;
			LOG(DEBUG) << ppid << " to sleep...\n";
			sleep(2);
			LOG(DEBUG) << ppid << " sleep end...\n";
		}
	}

	LOG(INFO) << ppid << " " << __func__ << " get: " << str << "\n";

	ret = send(data.iActiveFd,str.c_str(),sizeof(str.c_str()),MSG_NOSIGNAL);
	LOG(DEBUG) << "ret: " << ret << "\n";
	if(ret == -1){
		perror("[send]");
		LOG(ERROR) << "send data error!!!\n";
	}
}

int epollin_task(taskArg* arg)
{
	// todo 判断客户端请求的数据头类型，执行相应的线程任务;
	
	//pthread_t threadid;
	//pthread_create(&threadid,NULL,startRoutine_epollTask,(void*)arg);

	std::thread test(startRoutine_epollTask,arg);
	test.detach();
}
