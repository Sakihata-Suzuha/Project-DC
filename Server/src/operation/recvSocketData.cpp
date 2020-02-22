#include <ostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include "operation.h"
#include "../thread_manager/thread_manager.h"
#include "../module/easylogging++.h"
#include "../def.h"

bool recvSocketData(void* arg, char* buf)
{
	if(arg == nullptr || buf == nullptr){
		LOG(ERROR) << "nullptr!!!\n";

		return false;
	}

	taskArg tArg = *((taskArg*)arg);
	int ret = -1;

	for(;;){
		ret = recv(tArg.iActiveFd,buf,_SOCKET_BUFFER_SIZE_,0);
		if(ret < 0) {
			if(errno == EAGAIN){
				LOG(DEBUG) << "EAGAIN...\n";
				//EPOLLONESHOT 的特性是只监听一次事件，导致后面 EPOLLIN 监听不到，
				//这里需要重新 reset，后续的 EPOLLIN 方可监听到 oneshot->read->失效->reset->oneshot->read
				//所以这是一个可重入函数吗？如果被信号打断了，导致缓冲区有两份 pb 呢？
				epoll_event ev;
				ev.data.fd = tArg.iActiveFd;
				ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET|EPOLLONESHOT;
				//ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET;
				epoll_ctl(tArg.iRootEpfd,EPOLL_CTL_MOD,tArg.iActiveFd,&ev);
				break;
			}
			else {
				perror("[recv]");
				LOG(ERROR) << "recv error!!!\ncode: " << ret << std::endl;
			}
		}
		else if(ret == 0) {
			LOG(INFO) << "peer has performed an orderly shutdown...\n";

			break;
		}
		else if(ret > 0) {
			if(ret == _SOCKET_BUFFER_SIZE_) {
				LOG(INFO) << "recv 1500 bytes...\n";
			}

			//预留操作
		}
	}

	LOG(INFO) << __func__ << " succ...\n";

	return true;
}
