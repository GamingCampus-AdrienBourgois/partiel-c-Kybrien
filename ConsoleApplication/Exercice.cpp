#include <filesystem>
#include <iostream>
#include <string>

#include "Exercice.h"

#include "StudentConfiguration.h"

#ifdef COMPILE_EXERCICE_EXAMPLE
#include "ExerciceExample.h"
#endif

#ifdef COMPILE_EXERCICE_1
#include "Exercice1.h"
#endif

#ifdef COMPILE_EXERCICE_2
#include "Exercice2.h"
#endif

#ifdef COMPILE_EXERCICE_3
#include "Exercice3.h"
#endif

int ExerciceBase::AutograderMain(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cout << "/!\\ No Exercice provided !" << std::endl;
		return -1;
	}

	if (argc <= 2)
	{
		std::cout << "/!\\ No Test provided !" << std::endl;
		return -1;
	}

	int exerciceId = std::stoi(argv[1]);
	int testId = std::stoi(argv[2]);

	std::cout << "Autograder : Test Exercice " << exerciceId << " with test " << testId << std::endl;

	return AutograderRunTest(exerciceId, testId);
}

int ExerciceBase::AutograderRunTest(int exerciceId, int testId)
{
	std::cout << "Working Directory : " << std::filesystem::current_path() << std::endl;

	ExerciceBase* exercice = nullptr;

	switch (exerciceId)
	{
#ifdef COMPILE_EXERCICE_EXAMPLE
	case 0:
		{
			exercice = new ExerciceExample();
			break;
		}
#endif
#ifdef COMPILE_EXERCICE_1
	case 1:
		{
			exercice = new Exercice1();
			break;
		}
#endif
#ifdef COMPILE_EXERCICE_2
	case 2:
		{
			exercice = new Exercice2();
			break;
		}
#endif
#ifdef COMPILE_EXERCICE_3
	case 3:
		{
			exercice = new Exercice3();
			break;
		}
#endif
	default:
		{
			std::cout << "/!\\ Exercice not found or not compiled ! Did you forget to enable the #COMPILE_EXERCICE_X ?" << std::endl;
			return -1;
		}
	}

	if (exercice->Check(testId))
		return 0;

	return -1;
}
