
#include <time.h>
#include <string>

#pragma once

inline std::string date_string()
{
	time_t t;
	struct tm* pTime;

	time(&t);
	pTime = localtime(&t);

	char time_str[50];

	strftime(time_str, sizeof time_str, "%x - %I:%M%p", pTime);
	return std::string(time_str);
}