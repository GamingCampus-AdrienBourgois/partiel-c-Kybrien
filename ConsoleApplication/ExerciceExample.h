#pragma once
#include "Exercice.h"

#include "SolutionExample.h"

class ExerciceExample : public Exercice<SolutionExample>
{
public:
	bool ExecuteTest(int _id) override
	{
		switch (_id)
		{
		case 0: return SolutionExample::Sum(-1, 1) == 0;
		case 1: return SolutionExample::Sum(10, 20) == 30;
		default: throw std::logic_error("Test not found !");
		}
	}
};
