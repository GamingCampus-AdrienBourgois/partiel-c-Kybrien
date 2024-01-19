#pragma once
#include <exception>
#include <iostream>

class ExerciceBase
{
public:
	static int AutograderMain(int argc, char** argv);
	static int AutograderRunTest(int exerciceId, int testId);

	bool Check(int _testId)
	{
		try
		{
			bool result = ExecuteTest(_testId);

			if (result)
				std::cout << "-> Result Test " << _testId << " : OK" << std::endl;
			else
				std::cout << "-> Result Test " << _testId << " : FAILURE" << std::endl;

			return result;
		}
		catch (std::exception& _exception)
		{
			std::cout << "/!\\ EXCEPTION DURING TEST" << std::endl;
			std::cout << _exception.what() << std::endl;
			return false;
		}
	}

	virtual bool ExecuteTest(int _testId)
	{
		return true;
	}
};

template<typename SolutionType>
class Exercice : public ExerciceBase
{
public:
	SolutionType Solution;
};
