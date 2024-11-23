//
// Created by othman on 23/11/2024.
//
#include "Article.h"

// Constructeur avec paramètres
Article::Article(const string& name, const string& author, const string& summary,
                 const string& editor, int id, const string& reviewTitle)
    : Document(name, author, summary), editor(editor), id(id), reviewTitle(reviewTitle) {}

// Méthode d'affichage spécifique aux articles
void Article::afficher() const {
    Document::afficher(); // Appelle la méthode de la classe de base
    cout << "Editeur : " << editor << endl;
    cout << "Numero d'edition : " << id << endl;
    cout << "Titre de la revue : " << reviewTitle << endl;
}

// Destructeur
Article::~Article() {
    cout << "Article \"" << getName() << "\" publie dans la revue \"" << reviewTitle
         << "\" detruit." << endl;
}
