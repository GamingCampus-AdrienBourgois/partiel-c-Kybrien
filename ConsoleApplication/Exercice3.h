#pragma once
#include "Exercice.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

#include "Solution3.h"

/*
 * Exercice 3 : Alphabetical Word Sorter
 *
 * This exercise is designed to create a program that sorts a list of words in alphabetical order.
 * As an input, a vector of words is given. You must store the words, sort the words in alphabetical order and then return the sorted list.
 * The programm should sort them in alphabetical order, regardless of their original case. It means that "Hello" and "hello" should be considered as the same word.
 *
 * If the vector is null or empty, the program must throw an exception.
 */

class Exercice3 : public Exercice<Solution3>
{
public:
	bool ExecuteTest(int _id) override
	{
		switch (_id)
		{
		case 0: return Test(Set1, 0, "A");
		case 1: return Test(Set2, 0, "agency");
		case 2:
			{
				try
				{
					Test(Set3, 0, "A");
					return false;
				}
				catch (const std::exception&)
				{
					return true;
				}
			}
		case 3: return Test(Set1, 5, "World");
		case 4: return Test(Set2, 15, "Raise");
		default: throw std::logic_error("Test not found !");
		}
	}

	bool Test(const std::vector<std::string>& _wordsSet, int _wordId, const std::string& _wordToTest)
	{
		Solution.SetWords(_wordsSet);
		Solution.SortWords();
		return Solution.GetSortedWords().at(_wordId) == _wordToTest;
	}

	std::vector<std::string> Set1 = {"Hello", "World", "This", "Is", "A", "Test"};
	std::vector<std::string> Set2 = {"prepare", "big", "Baby", "during", "article", "Left", "community", "war", "choice", "ten", "doctor", "main", "trouble", "involve", "main", "part", "area", "agency", "Water", "Raise"};
	std::vector<std::string> Set3 = {};
};

#endif
