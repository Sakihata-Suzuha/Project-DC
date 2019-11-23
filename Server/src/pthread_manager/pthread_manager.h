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
