//
// Created by othma on 26/10/2024.
//

// Tableau.h
#ifndef TABLEAU_H
#define TABLEAU_H

#include "Entree.h"  // Inclusion de la classe Entree
#include <iostream>
using namespace std;

class Tableau {
public:
    Tableau(int tailleMax);
    Tableau(const Tableau& autre);
    Tableau& operator=(const Tableau& autre);
    ~Tableau();

    void ajouter(Entree* nouvelleEntree);
    void afficher() const;
    int getNbelem() const;
    Entree* getEntree(int index) const;
    int getTailleMax() const;
    void supprimerEntree(int index);

private:
    int m_tailleMax;
    int m_nbelem;
    Entree** m_entrees;
};

#endif // TABLEAU_H
