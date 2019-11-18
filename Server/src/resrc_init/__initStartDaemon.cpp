#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./resrc_init.h"
#include "../Process_Manager/Process_Manager.h"
#include "../Log_Module/easylogging++.h"
#include "../def.h"

int __initStartDaemon(daemonCallback callback)
{
	int ret;
	pid_t pid;
	pid_t sid;
	int fd;

	pid = myFork();
	if(pid > 0){
		printf("main process exit...\n");
		LOG(DEBUG) << "main process exit...\n";

		exit(0);
	}

	sid = setsid();
	if(sid == -1){
		perror("[setsid]");
		LOG(ERROR) << "setsid failed...\n";

		return _PROCESS_SETSID_ERROR_;
	}
	/*
	ret = chdir("./");
	if(ret == -1){
		perror("[chdir]");
		LOG(WARNING) << "chdir failed...\n";
	}
	*/
	fd = open(_LOG_FDOUTPUT_FILE_,O_CREAT|O_RDWR|O_APPEND);
	if(fd == -1){
		perror("[open]");
		LOG(WARNING) << "open failed...\n";
	}

	ret = dup2(fd,STDIN_FILENO);
	ret = dup2(fd,STDOUT_FILENO);
	ret = dup2(fd,STDERR_FILENO);
	if(ret == -1){
		perror("[dup2]");
		LOG(WARNING) << "dup2 failed...\n";
	}

	LOG(INFO) << "create daemon complete, start task run...\n";
	
	callback(nullptr);

	LOG(WARNING) << "daemon termination!!! is this the result you want???\n";

	exit(0);
}
