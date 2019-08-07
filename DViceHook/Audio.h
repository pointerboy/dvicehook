#pragma once

#include <Windows.h>
#include <string>


class Audio
{
public:
	Audio(){}

	static void PlayWavFile(const char*, bool);
};

