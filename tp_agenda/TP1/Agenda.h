//
// Created by othma on 26/10/2024.
//

#ifndef AGENDA_H
#define AGENDA_H

#include "Tableau.h"  // Inclure la classe Tableau pour l'utiliser dans Agenda
#include <string>
using namespace std;

class Agenda {
public:
    Agenda(int tailleMax);                     // Constructeur
    Agenda(const Agenda& autre);               // Constructeur par copie
    Agenda& operator=(const Agenda& autre);    // Opérateur d'affectation
    ~Agenda();                                 // Destructeur

    void ajouter(string nom, string numero);   // Méthode pour ajouter une entrée
    void afficher() const;                     // Méthode pour afficher l'agenda
    void concat(Agenda &autreAgenda);          // Méthode pour concaténer deux agendas

private:
    Tableau* m_tableau;  // Pointeur vers un tableau contenant les entrées
};

#endif
