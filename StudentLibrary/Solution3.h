#pragma once

#include <string>
#include <vector>

#include "StudentConfiguration.h"
// Don't forget to enable the exercise in the SudentConfiguration.h file !
#ifdef COMPILE_EXERCICE_3

class Solution3 // Alphabetical Word Sorter
{
public:
	void SetWords(const std::vector<std::string>& _words);
	void SortWords();
	std::vector<std::string> GetSortedWords() const;

private:
	std::vector<std::string> words;
};

#endif
