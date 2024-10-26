#include "Tableau.h"
#include <iostream>

Tableau::Tableau(int tailleMax) : m_tailleMax(tailleMax), m_nbelem(0) {
    m_entrees = new Entree*[m_tailleMax];
}

Tableau::Tableau(const Tableau& autre) {
    m_tailleMax = autre.m_tailleMax;
    m_nbelem = autre.m_nbelem;
    m_entrees = new Entree*[m_tailleMax];
    for (int i = 0; i < m_nbelem; ++i) {
        m_entrees[i] = new Entree(*autre.m_entrees[i]);
    }
}

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

Tableau::~Tableau() {
    for (int i = 0; i < m_nbelem; ++i) {
        delete m_entrees[i];
    }
    delete[] m_entrees;
}

void Tableau::ajouter(Entree* nouvelleEntree) {
    if (m_nbelem < m_tailleMax) {
        m_entrees[m_nbelem] = nouvelleEntree;
        m_nbelem++;
    } else {
        std::cout << "Tableau plein, impossible d'ajouter une nouvelle entree." << std::endl;
    }
}

void Tableau::afficher() const {
    for (int i = 0; i < m_nbelem; ++i) {
        m_entrees[i]->afficher();
    }
}

int Tableau::getNbelem() const {
    return m_nbelem;
}

Entree* Tableau::getEntree(int index) const {
    if (index >= 0 && index < m_nbelem) {
        return m_entrees[index];
    }
    return nullptr;
}

int Tableau::getTailleMax() const {
    return m_tailleMax;
}
