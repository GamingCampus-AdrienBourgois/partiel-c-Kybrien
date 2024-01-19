#include "Solution1.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to){
	
    //si _from et _to sont les memes on retourne la valeur
	if (_from == _to) {
		return _value;
	}
    //on regarde en fonction de la valeur de _from
    switch (_from){
    case TemperatureUnits::CELSIUS:
        switch (_to)
        {
        //si _to est en Celsius on retourne la valeur apres la conversion
        case TemperatureUnits::FAHRENHEIT:
            return (_value * 9.0f / 5.0f) + 32.0f;
        case TemperatureUnits::KELVIN:
            return _value + 273.15f;
        default:
            break;
        }
        break;

    case TemperatureUnits::FAHRENHEIT:
        switch (_to)
        {
        //si _to est en Fahrenheit ""
        case TemperatureUnits::CELSIUS:
            return (_value - 32.0f) * 5.0f / 9.0f;
        case TemperatureUnits::KELVIN:
            return (_value - 32.0f) * 5.0f / 9.0f + 273.15f;
        default:
            break;
        }
        break;

    case TemperatureUnits::KELVIN:
        switch (_to)
        {
        //si _to est en Kelvin ""
        case TemperatureUnits::CELSIUS:
            return _value - 273.15f;
        case TemperatureUnits::FAHRENHEIT:
            return (_value - 273.15f) * 9.0f / 5.0f + 32.0f;
        default:
            break;
        }
        break;

    default:
        break;
    }

    //si _from ou _to n'est pas une valeur valide on retourne -1.0f
	return -1.0f;
}

#endif