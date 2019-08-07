#include "Audio.h"

void Audio::PlayWavFile(const char* file_name, bool complete = false)
{
	PlaySound((LPCSTR)file_name, NULL, SND_FILENAME | (complete ? SND_SYNC : SND_ASYNC));
}