#ifndef __THREAD_MANAGER_H__
#define __THREAD_MANAGER_H__

/*
 * 附带 epoll 根节点
 * 正在读写的套接字，文件描述符
*/
class taskArg {
public:
	int iRootEpfd;
	int iActiveFd;
};

/*
 * 获取套接字数据，进行任务分发，创建新的子线程
 * taskArg：携带信息
*/
extern int epollin_task(taskArg* arg);

/*
 *
*/
//extern void

#endif //__THREAD_MANAGER_H__
