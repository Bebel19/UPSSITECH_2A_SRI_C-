//
// Created by othman on 23/11/2024.
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
    // Constructeur avec parametres
    Document(const string& name, const string& author, const string& summary);

    // Constructeur par copie
    Document(const Document& other);

    // Operateur d'affectation (=)
    Document& operator=(const Document& other);

    // Destructeur
    ~Document();

    // Getter methods
    string getName() const;
    string getAuthor() const;
    string getSummary() const;

    // Methode d'affichage
    virtual void afficher() const;
};

#endif // DOCUMENT_H
