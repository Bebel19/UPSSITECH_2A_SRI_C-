//
// Created by othma on 22/10/2024.
//

#include "Tableau.h"

// Constructeur par défaut
Tableau::Tableau(int taille) : m_size(taille), m_nbElements(0) {
    m_pointer = new Entree*[m_size];  // Allocation dynamique du tableau de pointeurs
    for (int i = 0; i < m_size; ++i) {
        m_pointer[i] = nullptr;  // Initialisation des pointeurs à nullptr
    }
}

// Constructeur par copie
Tableau::Tableau(const Tableau& autre) : m_size(autre.m_size), m_nbElements(autre.m_nbElements) {
    m_pointer = new Entree*[m_size];
    for (int i = 0; i < m_nbElements; ++i) {
        m_pointer[i] = new Entree(*autre.m_pointer[i]);  // Copie des objets `Entree`
    }
}

// Destructeur
Tableau::~Tableau() {
    for (int i = 0; i < m_nbElements; ++i) {
        delete m_pointer[i];  // Libération des objets `Entree`
    }
    delete[] m_pointer;  // Libération du tableau de pointeurs
}

// Ajouter une entrée (nom + numéro)
void Tableau::ajouter(string nom, string numero) {
    if (m_nbElements < m_size) {
        m_pointer[m_nbElements] = new Entree(nom, stoi(numero));  // Ajout de l'entrée dynamique
        m_nbElements++;  // Incrémentation après l'ajout
    } else {
        cout << "Tableau plein, impossible d'ajouter de nouvelles entrées." << endl;
    }
}

// Supprimer une entrée par nom et numéro
void Tableau::supprimer(string nom, string numero) {
    for (int i = 0; i < m_nbElements; ++i) {
        if (m_pointer[i] != nullptr && m_pointer[i]->getName() == nom && m_pointer[i]->getNumber() == stoi(numero)) {
            delete m_pointer[i];  // Libérer l'entrée
            for (int j = i; j < m_nbElements - 1; ++j) {
                m_pointer[j] = m_pointer[j + 1];  // Décalage des éléments
            }
            m_pointer[--m_nbElements] = nullptr;  // Remet le dernier pointeur à nullptr
            break;
        }
    }
}

// Supprimer une entrée par nom uniquement
void Tableau::supprimer(string nom) {
    for (int i = 0; i < m_nbElements; ++i) {
        if (m_pointer[i] != nullptr && m_pointer[i]->getName() == nom) {
            delete m_pointer[i];  // Libérer l'entrée
            for (int j = i; j < m_nbElements - 1; ++j) {
                m_pointer[j] = m_pointer[j + 1];  // Décalage des éléments
            }
            m_pointer[--m_nbElements] = nullptr;  // Remet le dernier pointeur à nullptr
            break;
        }
    }
}

// Méthode d'affichage
void Tableau::afficher() const {
    for (int i = 0; i < m_nbElements; ++i) {
        if (m_pointer[i] != nullptr) {
            m_pointer[i]->show();  // Affiche chaque entrée
        }
    }
}
