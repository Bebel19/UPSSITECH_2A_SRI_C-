//
// Created by othma on 26/10/2024.
//

#ifndef ENTREE_H
#define ENTREE_H

#include <string>


class Entree {
public:
    // Constructeur
    Entree(std::string nom, std::string numero);

    // Methode pour afficher l'entree
    void afficher() const ;

private:
    std::string m_nom;
    std::string m_numero;
};



#endif //ENTREE_H
