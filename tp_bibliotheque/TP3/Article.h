//
// Created by othman on 23/11/2024.
//
#include "Document.h"


#ifndef ARTICLE_H
#define ARTICLE_H

#include "Document.h"
#include <string>
#include <iostream>
using namespace std;

class Article : public Document {
private:
  string editor;         // Nom de l'éditeur
  int id;                // Numéro d'édition
  string reviewTitle;    // Titre de la revue

public:
  // Constructeur avec paramètres
  Article(const string& name, const string& author, const string& summary,
          const string& editor, int id, const string& reviewTitle);

  // Méthode d'affichage spécifique aux articles
  void afficher() const override;

  // Destructeur
  ~Article();
};

#endif // ARTICLE_H



