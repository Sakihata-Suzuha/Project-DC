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
#include "../module/addressbook.pb.h"
#include "../module/msgTest.pb.h"

using namespace tutorial;

void* pthreadTask_myTest(void* arg)
{
	// todo if

	LOG(INFO) << std::this_thread::get_id() << " task begin...\n";

	taskArg tArg = *((taskArg*)arg);
	int ret = -1;
	int bufSize = 128;
	char buf[128];
	std::string pbbuf;
	Person person;

	memset(buf,'\0',bufSize);

	for(;;){
		ret = recv(tArg.iActiveFd,buf,bufSize,0);
		if(ret < 0){
			if(errno == EAGAIN){
				LOG(DEBUG) << "EAGAIN\n";

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
		}
	}

	pbbuf = buf;
	person.ParseFromString(pbbuf);

	LOG(DEBUG) << "name  : " << person.name() << std::endl;
	LOG(DEBUG) << "id    : " << person.id() << std::endl;
	LOG(DEBUG) << "email : " << person.email() << std::endl;
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

	tcpTest::test01 fk;
	fk.set_desc("motherfucker!!!");
	fk.set_idrn(777);

	std::string sendBuf;
	person.SerializeToString(&sendBuf);
	ret = send(tArg.iActiveFd,sendBuf.c_str(),sizeof(sendBuf.c_str()),MSG_NOSIGNAL);
	if(ret == -1){
		perror("[send]");
		LOG(ERROR) << "send person error!!!\n";
	}
}

int epollin_task(taskArg* arg)
{
	// todo 判断客户端请求的数据头类型，执行相应的线程任务;
	//test:	
	std::thread test(pthreadTask_myTest,arg);
	test.detach();
}
