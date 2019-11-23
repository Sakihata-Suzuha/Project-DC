/*
 *
*/
class threadArg {
public:
	int iRootEpfd;
	int iActiveFd;
};

/*
 *
*/
extern int epollin_task(threadArg* arg);
