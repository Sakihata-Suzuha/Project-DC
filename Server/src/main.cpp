#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include "Process_Manager/myFork.h"
#include "Process_Manager/myWaitpid.h"
#include "_startDaemon.h"

using namespace std;

int main(int argc, char* argv[])
{
		cout << "————————————————" "————————————————" << endl;

		int ret;

		ret = _startDaemon();

		for(;;);

		return 0;
}
