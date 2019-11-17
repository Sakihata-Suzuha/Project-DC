#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include "Process_Manager/myFork.h"
#include "Process_Manager/myWaitpid.h"
#include "_startDaemon.h"
#include "easylogging++.h"

using namespace std;
using namespace el;

INITIALIZE_EASYLOGGINGPP 

int main(int argc, char* argv[])
{
	Loggers::addFlag(LoggingFlag::StrictLogFileSizeCheck);
	Configurations conf("../bin/myLogConfig.conf");
	Loggers::reconfigureAllLoggers(conf);

	LOG(INFO) << "test777887382949347777777" << endl;

		int ret;

		ret = _startDaemon();

		for(;;);

		return 0;
}
