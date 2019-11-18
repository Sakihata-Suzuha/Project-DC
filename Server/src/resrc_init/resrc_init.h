/*
 *
*/
extern int logInit();

/*
 *
*/
typedef void(*daemonCallback)(void* data);
extern int __initStartDaemon(daemonCallback callback);
