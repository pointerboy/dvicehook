#pragma once

#include <string>
#include <fstream>

#include "commons.cpp"

class Logging
{
public:
	static void AddLogMessage(std::string str = "EMPTY");
	static void AddDebugMessage(std::string str, bool FUNCTION_SHOW, bool LINE_SHOW, bool FILE_SHOW, bool FUNC_SIGNATURE, bool FUNC_DECORATED);
};

