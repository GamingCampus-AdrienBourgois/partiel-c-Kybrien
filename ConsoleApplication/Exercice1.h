#pragma once
#include "Exercice.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

#include "Solution1.h"

/*
 * Exercice 1 : Temperature Converter
 *
 * This exercice aim to create a temperature converter between Celsius, Fahrenheit and Kelvin.
 * An enum TemperatureUnits is provided to help you.
 * All result will be approximated to 2 decimals for testing purpose.
 *
 * CONVERSION FORMULAS :
 *		Celsius to Fahrenheit °F = 9/5 (°C) + 32
 *		Kelvin to Fahrenheit °F = 9/5 (K - 273) + 32
 *		Fahrenheit to Celsius °C = 5/9 (°F - 32)
 *		Celsius to Kelvin K = °C + 273
 *		Kelvin to Celsius °C = K - 273
 *		Fahrenheit to Kelvin K = 5/9 (°F - 32) + 273
 */

class Exercice1 : public Exercice<Solution1>
{
public:
	bool ExecuteTest(int _id) override
	{
		switch (_id)
		{
		case 0: return Test(71.97f, TemperatureUnits::KELVIN, TemperatureUnits::CELSIUS, -201.18f);
		case 1: return Test(71.97f, TemperatureUnits::KELVIN, TemperatureUnits::FAHRENHEIT, -330.12f);
		case 2: return Test(71.97f, TemperatureUnits::CELSIUS, TemperatureUnits::KELVIN, 345.12f);
		case 3: return Test(21.56f, TemperatureUnits::CELSIUS, TemperatureUnits::CELSIUS, 21.56f);
		case 4: return Test(62.02f, TemperatureUnits::FAHRENHEIT, TemperatureUnits::CELSIUS, 16.68f);
		default: throw std::logic_error("Test not found !");
		}
	}

	bool AreAlmostEqual(float a, float b, float epsilon = 0.0001f) const
	{
		return std::fabs(a - b) < epsilon;
	}

	bool Test(float _value, TemperatureUnits _from, TemperatureUnits _to, float _result) const
	{
		return AreAlmostEqual(Solution1::ConvertTemperature(_value, _from, _to), _result, 0.01f);
	}
};

#endif
