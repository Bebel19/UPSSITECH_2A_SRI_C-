//
// Created by othman on 23/11/2024.
//
#include "Livre.h"

// Constructeur avec paramètres
Livre::Livre(const string& name, const string& author, const string& summary,
             const string& editor, int publishingYear)
    : Document(name, author, summary), editor(editor), publishingYear(publishingYear) {}

// Méthode d'affichage spécifique aux livres
void Livre::afficher() const {
    Document::afficher(); // Appelle la méthode de la classe de base
    cout << "Editeur : " << editor << endl;
    cout << "Annee de publication : " << publishingYear << endl;
}

// Destructeur
Livre::~Livre() {
    cout << "Livre \"" << getName() << "\" publie en " << publishingYear << " detruit." << endl;
}
