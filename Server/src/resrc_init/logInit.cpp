#include "../Log_Module/easylogging++.h"
#include "../def.h"
#include "./resrc_init.h"

using namespace el;

INITIALIZE_EASYLOGGINGPP

int logInit()
{
	Configurations logConf(_LOG_CONFIG_PATH_);
	Loggers::reconfigureAllLoggers(logConf);
	Loggers::addFlag(LoggingFlag::StrictLogFileSizeCheck);

	printf("%s successed...\n",__func__);
	LOG(DEBUG) << __func__ << " successed...\n";

	return 0;
}
