#include "./process_manager.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../def.h"
#include "../module/easylogging++.h"

pid_t myWaitpid_wnohang(pid_t pid,int* wstatus)
{
	if(wstatus == nullptr){
		printf("%s wstatus nullptr...\n",__func__);
		LOG(WARNING) << __func__ << " wstatus nullptr...\n";

		int* t = nullptr;
		wstatus = t;
	}

	pid_t retPid;
	int ret;

	retPid = waitpid(pid,wstatus,WNOHANG);
	if(retPid == -1){
		perror("[waitpid]");
		LOG(WARNING) << "waitpid failed, warning zombie process...\n";

		return retPid;
	}

	if(retPid == 0){
		printf("[%d] status no change...\n",pid);
		LOG(DEBUG) << pid << " status no change...\n";

		return retPid;
	}

	if(retPid > 0){
		printf("[%d] process finished...\n",retPid);
		LOG(DEBUG) << retPid << " process finished...\n";

		if(WIFEXITED(*wstatus)){
			printf("exit status code is %d...\n",WEXITSTATUS(*wstatus));
			LOG(INFO) << "exit status code is " << WEXITSTATUS(*wstatus) << "...\n";
		}
		else if(WIFSIGNALED(*wstatus)){
			printf("[%d] Abnormal Termination...\n",retPid);
			printf("signal is %d...\n",WTERMSIG(*wstatus));
			LOG(INFO) << retPid << " Abnormal Termination...\n";
			LOG(INFO) << "signal is " << WTERMSIG(*wstatus) << "...\n";
		}
		else{
			return _UNKNOWN_EVENT_;
		}
	}

	return retPid;
}
