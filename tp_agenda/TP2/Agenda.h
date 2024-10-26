//
// Created by othma on 26/10/2024.
//

// Agenda.h
#ifndef AGENDA_H
#define AGENDA_H

#include "Tableau.h"
#include <string>

class Agenda {
public:
    Agenda(int tailleMax);
    Agenda(const Agenda& autre);
    Agenda& operator=(const Agenda& autre);
    ~Agenda();

    Agenda& operator+=(const Entree& entree);
    Agenda operator+(const Agenda& autre) const;
    Entree* operator[](const std::string& nom) const;
    Agenda& operator-=(const std::string& nom);
    bool operator==(const Agenda& autre) const;
    bool operator/(const std::string& nom) const;
    void operator()(char lettre) const;

    void ajouter(std::string nom, std::string numero);
    void afficher() const;
    void concat(const Agenda &autreAgenda);

private:
    Tableau* m_tableau;
};

#endif // AGENDA_H
