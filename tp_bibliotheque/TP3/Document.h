//
// Created by othma on 23/11/2024.
//

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>
using namespace std;

class Document {
  private:
    string name;
    string author;
    string* summary;

    public:
      //COnstructeur avec parametres
      Document(const string& name, const string& author, const string& summary)
          : name(name), author(author), summary(new string(summary)) {}

      //Constructeur par copie
      Document(const Document& other)
          : name(other.name), author(other.author), summary(new string(*other.summary)) {}


      //Destructeur
     ~Document(){
        delete summary;
        }

    // Opérateur d'affectation (=)
    Document& operator=(const Document& other) {
          if (this != &other) { // Vérifie l'auto-affectation
              // Libère l'ancienne mémoire
              delete summary;

              // Copie les nouveaux attributs
              name = other.name;
              author = other.author;

              // Alloue une nouvelle mémoire pour le résumé
              summary = new string(*other.summary);
          }
          return *this;
      }
    //Getters
    string getName() const { return name; }
    string getAuthor() const {return author;}
    string getSummary() const {return *summary;}
    // Méthode d'affichage
    void afficher() const {
          cout << "Nom: " << name << endl;
          cout << "Auteur: " << author << endl;
          cout << "Resume: " << *summary << endl;
      }

};



#endif //DOCUMENT_H
