//
// Created by othman on 23/11/2024.
//

#ifndef LIVRE_H
#define LIVRE_H

#include "Document.h"
#include <string>
#include <iostream>
using namespace std;

class Livre : public Document {
private:
    string editor;         // Editeur du livre
    int publishingYear;    // Annee de publication

public:
    // Constructeur avec paramètres
    Livre(const string& name, const string& author, const string& summary,
          const string& editor, int publishingYear);

    // Méthode d'affichage spécifique aux livres
    void afficher() const override;

    // Destructeur
    ~Livre();
};

#endif // LIVRE_H
