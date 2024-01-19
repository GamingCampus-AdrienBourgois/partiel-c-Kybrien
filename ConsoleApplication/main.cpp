#include <iostream>
#include "Exercice.h"

#ifndef AUTOGRADING
#include "StudentConfiguration.h"
#endif

int main(int argc, char** argv)
{
#ifndef AUTOGRADING

	std::cout << "Local test" << std::endl;

	/*------------------------------ !!! Don't touch above !!! ------------------------------*/
	/*------------------------------------ STUDENT MAIN ------------------------------------*/

	// This is the main function for the student

	// You can use this function to test a specific exercice, for example exercice 1 test 1
	// You can test multiple exercices by calling multiple times the function AutograderRunTest
	ExerciceBase::AutograderRunTest(0, 0);
	ExerciceBase::AutograderRunTest(0, 1);

	return 0;

	/*------------------------------------ STUDENT MAIN ------------------------------------*/
	/*------------------------------ !!! Don't touch after !!! ------------------------------*/

#else
	// This line is used by the autograder, don't touch it !
	return ExerciceBase::AutograderMain(argc, argv);
#endif
}
