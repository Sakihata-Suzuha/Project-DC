#include "./resource_init.h"
#include "../def.h"
#include "../module/easylogging++.h"

INITIALIZE_EASYLOGGINGPP
#define ELPP_THREAD_SAFE

int logInit()
{
	el::Configurations logConf(_LOG_CONFIG_PATH_);
	el::Loggers::reconfigureAllLoggers(logConf);
	el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);

	printf("\n----------------\n\n");
	LOG(DEBUG) << __func__ << " successed...\n";

	return 0;
}
