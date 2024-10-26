//
// Created by othma on 26/10/2024.
//

#ifndef TABLEAU_H
#define TABLEAU_H

#include "Entree.h"

class Tableau {
public:
    // Constructeur pour initialiser un tableau de taille donnee
    Tableau(int tailleMax);

    // Constructeur par copie profonde
    Tableau(const Tableau& autre);

    // Operateur d'affectation
    Tableau& operator=(const Tableau& autre);

    // Destructeur pour liberer la memoire allouee
    ~Tableau();

    // Methode pour ajouter une nouvelle entree
    void ajouter(Entree* nouvelleEntree);

    // Methode pour afficher toutes les entrees du tableau
    void afficher() const;
    // Methode pour obtenir le nombre d'elements
    int getNbelem() const;

    // Methode pour obtenir une entree à un index donne
    Entree* getEntree(int index) const;

    // Methode pour obtenir la taille maximale du tableau
    int getTailleMax() const;

private:
    int m_tailleMax;      // Taille maximale du tableau
    int m_nbelem;         // Nombre d'elements actuellement dans le tableau
    Entree** m_entrees;   // Pointeur vers un tableau d'entrees
};



#endif //TABLEAU_H

//TODO SUPPRIMER