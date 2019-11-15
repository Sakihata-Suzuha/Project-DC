#include <stdio.h>
#include "myWaitpid.h"

int myWaitpid(pid_t pid, int* term)
{
		pid_t ret;
		int wstatus;

		ret = waitpid(pid,&wstatus,WNOHANG);
		if(ret < 0){
				perror("[waitpid]");
				goto err1;
		}
		else if(ret == 0){
				printf("[%d]status no change...\n",pid);
				return ret;
		}
		else if(ret > 0){
				printf("[%d]process finished\n",ret);

				if(WIFEXITED(wstatus)){
						printf("exit status is %d...\n",WEXITSTATUS(wstatus));

						if(term != nullptr){
								*term = WEXITSTATUS(wstatus);
						}
				}
				else if(WIFSIGNALED(wstatus)){
						printf("[%d]is abnormal termination\n",ret);
						printf("signal is %d...\n",WTERMSIG(wstatus));

						if(term != nullptr){
								*term = WTERMSIG(wstatus);
						}
				}
		}

err1:
		return ret;
}
