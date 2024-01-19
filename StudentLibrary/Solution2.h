#pragma once

#include <string>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

class Solution2 // Bank Account
{
public:
	static float GetBalance(const std::string& accountName);
};

#endif
