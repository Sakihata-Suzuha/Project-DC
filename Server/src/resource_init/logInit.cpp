#include "../module/easylogging++.h"
#include "../def.h"
#include "./resource_init.h"

using namespace el;

INITIALIZE_EASYLOGGINGPP
#define ELPP_THREAD_SAFE

int logInit()
{
	Configurations logConf(_LOG_CONFIG_PATH_);
	Loggers::reconfigureAllLoggers(logConf);
	Loggers::addFlag(LoggingFlag::StrictLogFileSizeCheck);

	printf("\n----------------\n\n");
	LOG(DEBUG) << __func__ << " successed...\n";

	return 0;
}
