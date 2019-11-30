#ifndef __PROCESS_MANAGER_H__
#define __PROCESS_MANAGER_H__

#include <sys/types.h>
#include <unistd.h>

/*
 *
*/
extern pid_t myFork();

/*
 *
*/
extern pid_t myWaitpid_wnohang(pid_t pid,int* wstatus);

/*
 *
*/
typedef void(*daemonCallback)(void* data);
extern int __StartDaemon(daemonCallback callback);

#endif
