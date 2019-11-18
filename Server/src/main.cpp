#include <stdio.h>
#include <stdlib.h>
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
	// test begin
	int lfd = registerListenSocket();
	myWaitpid_wnohang(getpid(),nullptr);

	for(int i = 0; i < 6; ++i)
	{
		sleep(8);

		LOG(DEBUG) << "test successed...\n";
	}
	// test end
}

int main(int argc, char* argv[])
{
	printf("\n\n");

	int ret;

	ret = logInit();
	ret = __initStartDaemon(core);
	if(ret < 0){
		printf("initStartDaemon error!!!\n");
		LOG(FATAL) << "initStartDaemon error!!!\n";
	}
}
