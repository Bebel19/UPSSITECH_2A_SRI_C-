//
// Created by othma on 26/10/2024.
//

#include "Entree.h"

#include <iostream>
#include <string>

using namespace std;


// Constructeur
Entree :: Entree(string nom, string numero) : m_nom(nom), m_numero(numero) {}

// Methode pour afficher l'entree
void Entree :: afficher() const {
    cout << "Nom : " << m_nom << ", Numero : " << m_numero << endl;
}



