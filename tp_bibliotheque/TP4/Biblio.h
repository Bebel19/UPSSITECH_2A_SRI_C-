//
// Created by othma on 23/11/2024.
//

#ifndef BIBLIO_H
#define BIBLIO_H


#include <list>
#include <iostream>
#include "Document.h"
using namespace std;

class Biblio {
    private :
      string name;
    public:
      //constructeur
      Biblio(string & name);

      //methode pour ajouter un document à la bibliotheque
      void ajouter(Document *document);
      void rechercher(string querry);
      void afficher();

      //destructeur
      ~Biblio();
};



#endif //BIBLIO_H
