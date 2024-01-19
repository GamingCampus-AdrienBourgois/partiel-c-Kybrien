#include "Solution2.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ostream>

// Don't forget to enable the exercise in the SudentConfiguration.h file !
//C'est bon merci (il etait caché j'ai galéré a le trouver)  :)

#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
    //On s'occupe d'abord la lecture du fichier comme tu l'as demande
    std::string filePath = "BankAccount/" + accountName + ".txt";

    //Puis ouvre le fichier
    std::ifstream file(filePath);

    if (!file.is_open()) {
        // Lever une exception si le fichier n'a pas pu être ouvert
        throw std::runtime_error("Impossible d'ouvrir le fichier :( -> " + filePath);
    }

    //On fait toutes les variables dont on aura besoin
    float balance = 0.0f;
    float amount;
    char operationType;
    
    

    //On lit le fichier
    while (file >> operationType >> amount) {
        // On met a jour le solde en fonction du type d'opération (dépôt+ ou retrait-)
        if (operationType == '+') {
            balance += amount;
        }
        else if (operationType == '-') {
            balance -= amount;
        }
        else {
            // Exception au cas ou ca marche pas on sait jamais
            throw std::invalid_argument("Operation invalide dans ce fichier :( -> " + filePath);
        }
    }

    // Fermer le fichier
    file.close();

    // Retourner le solde calculé
    return balance;
}

#endif
