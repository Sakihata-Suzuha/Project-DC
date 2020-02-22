#ifndef __THREAD_MANAGER_H__
#define __THREAD_MANAGER_H__

/*
 *
*/
class taskArg {
public:
	int iRootEpfd;
	int iActiveFd;
};

/*
 *
*/
extern void* pthreadTask_myTest(void* arg);
extern int epollin_task(taskArg* arg);

#endif
