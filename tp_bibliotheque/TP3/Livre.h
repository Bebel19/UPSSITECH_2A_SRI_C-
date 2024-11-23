//
// Created by othma on 23/11/2024.
//

#ifndef LIVRE_H
#define LIVRE_H

#include "Document.h"

class Livre : public Document {
    private:
      string editor;
      int publishingYear;

    public:
      Livre(const string & name, const string & author, const string & summary, const string & editor, const int publishingYear)
          : Document(name, author, summary), editor(editor), publishingYear(publishingYear) {}

    //Methode d'affichage spécifique aux livres
    void afficher() const {
       Document::afficher();
       cout << "Editeur : " << editor << endl;
       cout << "Annee de publication : " << publishingYear << endl;
       }

    // Destructeur
    ~Livre() {
         cout << "Livre " << getName() << " publie en " << publishingYear << " detruit." <<endl;
         }
};



#endif //LIVRE_H
