//
// Created by othma on 26/10/2024.
//

#include "Agenda.h"
#include <iostream>

Agenda::Agenda(int tailleMax) : m_tableau(new Tableau(tailleMax)) {}

Agenda::Agenda(const Agenda& autre) {
    m_tableau = new Tableau(*autre.m_tableau);
}

Agenda& Agenda::operator=(const Agenda& autre) {
    if (this != &autre) {
        delete m_tableau;
        m_tableau = new Tableau(*autre.m_tableau);
    }
    return *this;
}

Agenda::~Agenda() {
    std::cout << "Destruction de l'agenda" << std::endl;
    delete m_tableau;
}

void Agenda::ajouter(string nom, string numero) {
    m_tableau->ajouter(new Entree(nom, numero));
}

void Agenda::afficher() const {
    std::cout << "Contenu de l'agenda :" << std::endl;
    m_tableau->afficher();
}

void Agenda::concat(Agenda &autreAgenda) {
    std::cout << "Concatenation de deux agendas." << std::endl;

    for (int i = 0; i < autreAgenda.m_tableau->getNbelem(); i++) {
        Entree* entree = autreAgenda.m_tableau->getEntree(i);
        if (entree != nullptr && m_tableau->getNbelem() < m_tableau->getTailleMax()) {
            m_tableau->ajouter(new Entree(*entree));  // Copie l'entree
        } else if (entree == nullptr) {
            std::cout << "Erreur : Pointeur d'entree invalide à l'index " << i << std::endl;
        } else {
            std::cout << "L'agenda est plein, impossible d'ajouter plus d'entrees." << std::endl;
            break;
        }
    }

    // Afficher le contenu de l'agenda apres concatenation
    std::cout << "Contenu de l'agenda apres concatenation :" << std::endl;
    m_tableau->afficher();
}
