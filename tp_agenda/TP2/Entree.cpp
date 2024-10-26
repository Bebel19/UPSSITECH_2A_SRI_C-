//
// Created by othma on 26/10/2024.
//
// Entree.cpp
#include "Entree.h"

Entree::Entree(string nom, string numero) : m_nom(nom), m_numero(numero) {}

void Entree::afficher() const {
    cout << "Nom : " << m_nom << ", Numero : " << m_numero << endl;
}

string Entree::getNom() const { return m_nom; }

bool Entree::operator!=(const Entree& autre) const {
    return m_nom != autre.m_nom || m_numero != autre.m_numero;
}
