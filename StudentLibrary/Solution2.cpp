#include "Solution2.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ostream>

// Don't forget to enable the exercise in the SudentConfiguration.h file !
//C'est bon merci (il etait cach� j'ai gal�r� a le trouver)  :)

#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
    // On construit le chemin du fichier � lire pour le retrouver dans le dossier BankAccount
    std::string filePath = "BankAccount/" + accountName + ".txt";

    // On l'ouvre en lecture
    std::ifstream file(filePath);

    if (!file.is_open()) {
        // Lever une exception si le fichier n'a pas pu �tre ouvert
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    // Variables pour stocker les op�rations du compte
    std::string operationType;
    float amount;
    float balance = 0.0f;

    // Lire chaque ligne du fichier
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> operationType >> amount)) {
            // Lever une exception en cas de ligne invalide
            throw std::invalid_argument("Ligne non valide dans ce fichier :( -> " + filePath);
        }

        // On met a jour le solde en fonction du type d'op�ration
        if (operationType == "DEPOSIT") {
            balance += amount;
        }
        else if (operationType == "WITHDRAW") {
            balance -= amount;
        }
        else {
            // Exception en cas d'op�ration invalide :(
            throw std::invalid_argument("Invalid operation type in file: " + filePath);
        }
    }

    // Fermer le fichier
    file.close();

    // Retourner le solde calcul�
    return balance;
}

#endif
