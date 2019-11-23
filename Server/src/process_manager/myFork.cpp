#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/unistd.h>
#include <signal.h>
#include "../module/easylogging++.h"
#include "../def.h"
#include "./process_manager.h"

pid_t myFork()
{
	pid_t funcPid;
	int ret;

	funcPid = fork();
	if(funcPid == -1){
		perror("[fork]");
		LOG(WARNING) << "create child process failed...\n";

		ret = kill(getpid(),SIGUSR1);
		if(ret == -1){
			perror("[kill]");
			LOG(ERROR) << "kill failed...\n";

			abort();
		}
	}

	if(funcPid == 0){
		printf("child process is created...\n");
		LOG(DEBUG) << "child process is created...\n";

		return funcPid;
	}
	else if(funcPid > 0){
		printf("parent print: child process is %d...\n",funcPid);
		LOG(DEBUG) << "parent print: child process is " << funcPid << "...\n";

		return funcPid;
	}

	return _UNKNOWN_EVENT_;
}
