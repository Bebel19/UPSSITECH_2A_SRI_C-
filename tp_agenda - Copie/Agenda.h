//
// Created by othma on 22/10/2024.
//

#ifndef AGENDA_H
#define AGENDA_H


// Agenda.h
#include "Tableau.h"

class Agenda {
private:
    Tableau* tableau;

public:
    Agenda(int tailleMax);
    ~Agenda();
    Agenda(const Agenda& autre);

    void ajouter(string nom, string numero);
    void supprimer(string nom);
    void afficher() const;
    Agenda concat(const Agenda& autre) const;
};

// Implémentation dans Agenda.cpp

Agenda::Agenda(int tailleMax) {
    tableau = new Tableau(tailleMax);
}

Agenda::~Agenda() {
    delete tableau;
}

Agenda::Agenda(const Agenda& autre) {
    tableau = new Tableau(*autre.tableau);
}

void Agenda::ajouter(string nom, string numero) {
    tableau->ajouter(nom, numero);
}

void Agenda::supprimer(string nom) {
    tableau->supprimer(nom);
}

void Agenda::afficher() const {
    tableau->afficher();
}

Agenda Agenda::concat(const Agenda& autre) const {
    Agenda nouveauAgenda(tableau->getTaille() + autre.tableau->getTaille());
    for (int i = 0; i < tableau->getNbElements(); ++i) {
        // Ajoute les éléments du premier agenda
    }
    for (int i = 0; i < autre.tableau->getNbElements(); ++i) {
        // Ajoute les éléments du second agenda
    }
    return nouveauAgenda;
}



#endif //AGENDA_H
