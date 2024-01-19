#include "Solution3.h"
#include <algorithm>
#include <stdexcept>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
//C'est bon :) Je me suis permis d'utiliser un compilateur en ligne pour tester mon code, j'espere que c'est pas grave :p (et encore ca a pas facilité les choses)


#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

void Solution3::SetWords(const std::vector<std::string>& _words)
{
    words = _words;
}

void Solution3::SortWords() {

    // On tri les mots 
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {

        // On utilise std::lexicographical_compare pour comparer les mots sans tenir compte de la premiere lettre (maj ou minuscule) Merci CPPreference !
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) {

            // On compare les lettres, toutes mises en minuscule grace au stt::tolower
            return std::tolower(c1) < std::tolower(c2);
            });
        });
}

// On retourne le vecteur de mots triés
std::vector<std::string> Solution3::GetSortedWords() const
{
    return words;
}

#endif
