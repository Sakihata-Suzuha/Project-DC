#include <google/protobuf/stubs/port.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <iostream>
#include <string>
#include <thread>
#include "./thread_manager.h"
#include "../module/easylogging++.h"
#include "../def.h"
#include "../proto_src/msgTest.pb.h"
#include "../proto_src/transeTest.pb.h"

using namespace msgTest;
using namespace transeTest;

int i = 0;

void* pthreadTask_myTest(void* arg)
{
	// todo if

	LOG(INFO) << std::this_thread::get_id() << " task begin...\n";

	taskArg tArg = *((taskArg*)arg);
	int ret = -1;
	int bufSize = 128;
	char buf[128];

	memset(buf,'\0',bufSize);

	/*	
		if(person.ParseFromFileDescriptor(tArg.iActiveFd))
		LOG(INFO) << "ParseFromFileDescriptor succ...\n";
		else
		LOG(INFO) << "ParseFromFileDescriptor error...\n";
		*/

	for(;;){
		ret = recv(tArg.iActiveFd,buf,bufSize,0);
		if(ret < 0){
			if(errno == EAGAIN){
				LOG(DEBUG) << "EAGAIN\n";
				//EPOLLONESHOT 的特性是只监听一次事件，导致后面 EPOLLIN 监听不到，
				//这里需要重新 reset，后续的 EPOLLIN 方可监听到 oneshot->read->失效->reset->oneshot->read
				//所以这是一个可重入函数吗？如果被信号打断了，导致缓冲区有两份 pb 呢？
				epoll_event ev;
				ev.data.fd = tArg.iActiveFd;
				ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET|EPOLLONESHOT;
				//ev.events = EPOLLIN|EPOLLRDHUP|EPOLLERR|EPOLLET;
				epoll_ctl(tArg.iRootEpfd,EPOLL_CTL_MOD,tArg.iActiveFd,&ev);
				//
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
//			LOG(DEBUG) << "goto sleep...\n";
		}
	}

	std::string msgbuf(buf);
	std::string transebuf(buf);

	testBody_a st1;
	testBody_b st2;

	st1.ParseFromString(msgbuf);
	st2.ParseFromString(transebuf);

	LOG(INFO) << "idrn: " << st1.idrn() << std::endl;
	LOG(INFO) << "desc: " << st1.desc() << std::endl;
	LOG(DEBUG) << "------------------------------\n";
	LOG(INFO) << "id: " << st2.id() << std::endl;
	LOG(INFO) << "num: " << st2.double_test() << std::endl;
	
	/*
	   person.set_name("bbbb");
	   person.set_id(2222);
	   person.set_email("bbbb@2222.com");

	   std::string sendBuf;
	   person.SerializeToString(&sendBuf);
	   ret = send(tArg.iActiveFd,sendBuf.c_str(),sizeof(sendBuf.c_str()),MSG_NOSIGNAL);
	   if(ret == -1){
	   perror("[send]");
	   LOG(ERROR) << "send person error!!!\n";
	   }
	   */


	LOG(INFO) << "[" << ++i << "] " << std::this_thread::get_id() << " task end...\n";
}

int epollin_task(taskArg* arg)
{
	// todo 判断客户端请求的数据头类型，执行相应的线程任务;
	//test:	
		std::thread pTask(pthreadTask_myTest,arg);
		pTask.detach();
}
