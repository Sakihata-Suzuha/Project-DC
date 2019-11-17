#include <sys/types.h>
#include <unistd.h>

/*
 *
*/
extern pid_t myFork();

/*
 *
*/
extern pid_t mywaitpid_wnohang(pid_t pid,int* wstatus);
