//
// Created by othma on 26/10/2024.
//
// Agenda.cpp
#include "Agenda.h"

// Constructeur
Agenda::Agenda(int tailleMax) : m_tableau(new Tableau(tailleMax)) {}

// Constructeur par copie
Agenda::Agenda(const Agenda& autre) : m_tableau(new Tableau(*autre.m_tableau)) {}

// Opérateur d'affectation
Agenda& Agenda::operator=(const Agenda& autre) {
    if (this != &autre) {
        delete m_tableau;
        m_tableau = new Tableau(*autre.m_tableau);
    }
    return *this;
}

// Destructeur
Agenda::~Agenda() {
    delete m_tableau;
}

// Opérateur += pour ajouter une entrée
Agenda& Agenda::operator+=(const Entree& entree) {
    m_tableau->ajouter(new Entree(entree));
    return *this;
}

// Opérateur + pour concaténer deux agendas
Agenda Agenda::operator+(const Agenda& autre) const {
    Agenda resultat(m_tableau->getTailleMax() + autre.m_tableau->getTailleMax());
    resultat.concat(*this);
    resultat.concat(autre);
    return resultat;
}

// Accès par nom (opérateur [])
Entree* Agenda::operator[](const std::string& nom) const {
    for (int i = 0; i < m_tableau->getNbelem(); i++) {
        if (m_tableau->getEntree(i)->getNom() == nom) {
            return m_tableau->getEntree(i);
        }
    }
    return nullptr;
}

// Opérateur -= pour supprimer une entrée par nom
Agenda& Agenda::operator-=(const std::string& nom) {
    for (int i = 0; i < m_tableau->getNbelem(); i++) {
        if (m_tableau->getEntree(i)->getNom() == nom) {
            m_tableau->supprimerEntree(i);
            i--;
        }
    }
    return *this;
}

// Opérateur == pour comparer deux agendas
bool Agenda::operator==(const Agenda& autre) const {
    if (m_tableau->getNbelem() != autre.m_tableau->getNbelem()) {
        return false;
    }
    for (int i = 0; i < m_tableau->getNbelem(); i++) {
        if (*(m_tableau->getEntree(i)) != *(autre.m_tableau->getEntree(i))) {
            return false;
        }
    }
    return true;
}

// Opérateur / pour vérifier la présence d'un nom
bool Agenda::operator/(const std::string& nom) const {
    for (int i = 0; i < m_tableau->getNbelem(); i++) {
        if (m_tableau->getEntree(i)->getNom() == nom) {
            return true;
        }
    }
    return false;
}

// Opérateur () pour afficher les entrées par initiale
void Agenda::operator()(char lettre) const {
    for (int i = 0; i < m_tableau->getNbelem(); i++) {
        if (m_tableau->getEntree(i)->getNom()[0] == lettre) {
            m_tableau->getEntree(i)->afficher();
        }
    }
}

// Ajouter une nouvelle entrée
void Agenda::ajouter(std::string nom, std::string numero) {
    m_tableau->ajouter(new Entree(nom, numero));
}

// Afficher tout l'agenda
void Agenda::afficher() const {
    m_tableau->afficher();
}

// Concaténer deux agendas
void Agenda::concat(const Agenda& autreAgenda) {
    for (int i = 0; i < autreAgenda.m_tableau->getNbelem(); i++) {
        Entree* entree = autreAgenda.m_tableau->getEntree(i);
        if (entree != nullptr && m_tableau->getNbelem() < m_tableau->getTailleMax()) {
            m_tableau->ajouter(new Entree(*entree));
        } else if (entree == nullptr) {
            cout << "Erreur : Pointeur d'entree invalide à l'index " << i << endl;
        } else {
            cout << "L'agenda est plein, impossible d'ajouter plus d'entrees." << endl;
            break;
        }
    }
}
