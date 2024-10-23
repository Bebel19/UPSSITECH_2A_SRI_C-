//
// Created by othma on 22/10/2024.
//


#ifndef TABLEAU_H
#define TABLEAU_H

#include "Entree.h"
#include <iostream>

class Tableau {
public:
    // Constructeur par défaut
    Tableau(int taille = 10);

    // Constructeur par copie
    Tableau(const Tableau& autre);

    // Destructeur
    ~Tableau();

    // Méthodes
    void ajouter(string nom, string numero);
    void supprimer(string nom, string numero);
    void supprimer(string nom);
    void afficher() const;

    // Getters (Accesseurs)
    int getTaille() const { return m_size; }
    int getNbElements() const { return m_nbElements; }

private:
    // Attributs
    int m_size;          // Taille totale du tableau
    Entree* m_pointer;   // Pointeur vers un tableau d'entrées
    int m_nbElements;    // Nombre actuel d'éléments dans le tableau
};

#endif //TABLEAU_H

