//
// Created by othma on 26/10/2024.
//

// Entree.h
#ifndef ENTREE_H
#define ENTREE_H

#include <string>
#include <iostream>
using namespace std;

class Entree {
public:
    Entree(string nom, string numero);
    void afficher() const;
    string getNom() const;
    bool operator!=(const Entree& autre) const;
private:
    string m_nom;
    string m_numero;
};

#endif // ENTREE_H
