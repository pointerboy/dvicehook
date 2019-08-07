#include "DVLogging.h"

void Logging::AddLogMessage(std::string str)
{
	std::ofstream pLocalLog;

	pLocalLog.open("DViceHookLog.txt", std::ios_base::app);
	pLocalLog << "[" << date_string() << "] " << str << std::endl;
	pLocalLog.close();
}

void Logging::AddDebugMessage(std::string str,
	bool FUNCTION_SHOW,
	bool LINE_SHOW,
	bool FILE_SHOW,
	bool FUNC_SIGNATURE,
	bool FUNC_DECORATED)
{
	Logging::AddLogMessage("* Start of debug trace:");
	std::string debug_buffer;

	if (FUNCTION_SHOW)
	{
		debug_buffer.append(__FUNCTION__);
		debug_buffer.append(" \n ");
	}

	
	if (FILE_SHOW) 
	{
		debug_buffer.append(__FILE__);
		debug_buffer.append(" \n ");
	}

	if (FUNC_SIGNATURE)
	{
		debug_buffer.append(__FUNCSIG__);
		debug_buffer.append(" \n ");
	}

	if (FUNC_DECORATED)
	{
		debug_buffer.append(__FUNCDNAME__);
		debug_buffer.append(" \n ");
	}
	
	Logging::AddLogMessage(debug_buffer);
}