#include <stdio.h>
#include <iostream>
#include "myFork.h"

pid_t myFork()
{
		std::cout << __func__ << ": start..." << std::endl;

		pid_t pid;

		pid = fork();
		if(pid < 0){
				perror("[fork]");
				exit(10001);		//todo errCode enum
		}
		else if(pid == 0){
				std::cout << "fork succ, child proc start..." << std::endl;
				return pid;
		}
		else if(pid > 0){
				std::cout << "parent proc fork succ, get child pid: " << pid << std::endl;
				return pid;
		}
}
