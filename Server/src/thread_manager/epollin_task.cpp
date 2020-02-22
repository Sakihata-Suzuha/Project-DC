#include <stdlib.h>
#include <string.h>
#include <thread>
#include "thread_manager.h"
#include "../operation/operation.h"
#include "../def.h"
#include "../module/easylogging++.h"
		/////////////////////////////////////////
#include "../proto_src/msgTest.pb.h"
#include "../proto_src/transeTest.pb.h"
		/////////////////////////////////////////
#include "../proto_src/root.pb.h"
#include "../proto_src/userLogin.pb.h"
		
using namespace std;

int epollin_task(taskArg* arg)
{
	LOG(INFO) << this_thread::get_id() << " epollin_task begin...\n";

	char* buf = (char*)malloc(_SOCKET_BUFFER_SIZE_);
	memset(buf,'\0',_SOCKET_BUFFER_SIZE_);
	if(recvSocketData((void*)arg, buf)) {
		/////////////////////////////////////////
		std::string msgbuf(buf);
		      std::string transebuf(buf);
			    
			  msgTest::testBody_a st1;
			  transeTest::testBody_b st2;
			    
			        st1.ParseFromString(msgbuf);
					      st2.ParseFromString(transebuf);
						    
						      LOG(INFO) << "idrn: " << st1.idrn() << std::endl;
						      LOG(INFO) << "desc: " << st1.desc() << std::endl;
						      LOG(INFO) << "id: " << st2.id() << std::endl;
						      LOG(INFO) << "num: " << st2.double_test() << std::endl;
		/////////////////////////////////////////
		string rootStr(buf);
		string loginStr(buf);

		root t1;
		userLogin::request t2;

		t1.ParseFromString(rootStr);
		t2.ParseFromString(loginStr);

		if(t1._type() == root::AccessType::root_AccessType_login){
			LOG(INFO) << "t1 yes! " << t1._type() << endl;
		}
						      LOG(DEBUG) << "------------------------------\n";
		if(t2.type() == root::AccessType::root_AccessType_login){
			LOG(INFO) << "t2 yes! " << t2.type() << endl;
		}
			LOG(INFO) << "uuid: " << t2.uuid() << endl;
			LOG(INFO) << "identifier: " << t2.identifier() << endl;
			LOG(INFO) << "pwd: " << t2.pwd() << endl;
		/////////////////////////////////////////
	}
	else {
		LOG(ERROR) << "recvSocketData error!!!\n";
	}

	free(buf);

	LOG(INFO) << this_thread::get_id() << " epollin_task end...\n";

	return 0;
}
