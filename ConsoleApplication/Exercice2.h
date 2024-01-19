#pragma once
#include "Exercice.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

#include "Solution2.h"

/*
 * Exercice 2 : Bank Account
 *
 * In the folder "BankAccount", you will find multiple documents "XXXXXX.txt" that represents the operations of a bank account.
 * You must provide a solution that will read the file and compute the balance of the account.
 * Two types of operations are available : DEPOSIT (+) and WITHDRAW (-).
 *
 * During compilation, each BankAccount.txt will be copied to the build folder inside the "BankAccount" folder, next to the .exe. To open the file, simply use the "BankAccount/XXXXXX.txt" file path.
 * If the file is not found, the program must throw an exception.
 */

class Exercice2 : public Exercice<Solution2>
{
public:
	bool ExecuteTest(int _id) override
	{
		switch (_id)
		{
		case 0: return Test("159874", 525.37f);
		case 1: return Test("784512", 113.16f);
		case 2: return Test("846326", 130.20f);
		case 3:
			{
				try
				{
					Solution2::GetBalance("1234569874512");
					return false;
				}
				catch ([[maybe_unused]] std::exception& _exception)
				{
					return true;
				}
			}
		case 4: return Test("968521", 295.46f);
		default: throw std::logic_error("Test not found !");
		}
	}

	bool AreAlmostEqual(float a, float b, float epsilon = 0.0001f) const
	{
		return std::fabs(a - b) < epsilon;
	}

	bool Test(const std::string& _accountName, float _result) const
	{
		return AreAlmostEqual(Solution2::GetBalance(_accountName), _result, 0.01f);
	}
};

#endif
