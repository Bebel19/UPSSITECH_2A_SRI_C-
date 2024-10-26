//
// Created by othma on 26/10/2024.
//
// Tableau.cpp
#include "Tableau.h"

// Constructeur pour initialiser un tableau de taille donnée
Tableau::Tableau(int tailleMax) : m_tailleMax(tailleMax), m_nbelem(0) {
    m_entrees = new Entree*[m_tailleMax];
}

// Constructeur par copie
Tableau::Tableau(const Tableau& autre) : m_tailleMax(autre.m_tailleMax), m_nbelem(autre.m_nbelem) {
    m_entrees = new Entree*[m_tailleMax];
    for (int i = 0; i < m_nbelem; ++i) {
        m_entrees[i] = new Entree(*autre.m_entrees[i]);
    }
}

// Opérateur d'affectation
Tableau& Tableau::operator=(const Tableau& autre) {
    if (this != &autre) {
        for (int i = 0; i < m_nbelem; ++i) {
            delete m_entrees[i];
        }
        delete[] m_entrees;

        m_tailleMax = autre.m_tailleMax;
        m_nbelem = autre.m_nbelem;
        m_entrees = new Entree*[m_tailleMax];
        for (int i = 0; i < m_nbelem; ++i) {
            m_entrees[i] = new Entree(*autre.m_entrees[i]);
        }
    }
    return *this;
}

// Destructeur
Tableau::~Tableau() {
    for (int i = 0; i < m_nbelem; ++i) {
        delete m_entrees[i];
    }
    delete[] m_entrees;
}

// Ajouter une nouvelle entrée
void Tableau::ajouter(Entree* nouvelleEntree) {
    if (m_nbelem < m_tailleMax) {
        m_entrees[m_nbelem] = nouvelleEntree;
        m_nbelem++;
    } else {
        cout << "Tableau plein, impossible d'ajouter une nouvelle entrée." << endl;
    }
}

// Afficher toutes les entrées
void Tableau::afficher() const {
    for (int i = 0; i < m_nbelem; ++i) {
        m_entrees[i]->afficher();
    }
}

// Obtenir le nombre d'éléments
int Tableau::getNbelem() const {
    return m_nbelem;
}

// Obtenir une entrée à un index donné
Entree* Tableau::getEntree(int index) const {
    return (index >= 0 && index < m_nbelem) ? m_entrees[index] : nullptr;
}

// Obtenir la taille maximale
int Tableau::getTailleMax() const {
    return m_tailleMax;
}

// Supprimer une entrée
void Tableau::supprimerEntree(int index) {
    if (index >= 0 && index < m_nbelem) {
        delete m_entrees[index];
        for (int i = index; i < m_nbelem - 1; i++) {
            m_entrees[i] = m_entrees[i + 1];
        }
        m_nbelem--;
    }
}
