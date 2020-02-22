#ifndef __DEF_H__
#define __DEF_H__


#define _UNKNOWN_EVENT_            -9999

////////////////////////////////////////////////////////////////

#define _PROCESS_SETSID_ERROR_     -10001

////////////////////////////////////////////////////////////////

#define _SOCKET_REGISTER_ERROR_    -20001
#define _SOCKET_BIND_ERROR_        -20002
#define _SOCKET_LISTEN_ERROR_      -20003
#define _EPOLL_CREATE_ERROR_       -20101
#define _EPOLL_CTL_ERROR_          -20102
#define _EPOLL_WAIT_ERROR_         -20103

////////////////////////////////////////////////////////////////

#define _SOCKET_LISTEN_SIZE_       1024 
#define _EPOLL_EVENT_SIZE_         1024 
#define _BUFFER_SIZE_              2048
#define _SOCKET_BUFFER_SIZE_       1500

#define _LOG_CONFIG_PATH_          "./config/myLogConfig.conf"
#define _LOG_FDOUTPUT_FILE_        "./log/fdPrint.log"


#endif //__DEF_H__
