//
// Created by othman on 23/11/2024.
//

#include "Document.h"

// Constructeur avec parametres
Document::Document(const string& name, const string& author, const string& summary)
    : name(name), author(author), summary(new string(summary)) {}

// Constructeur par copie
Document::Document(const Document& other)
    : name(other.name), author(other.author), summary(new string(*other.summary)) {}

// Operateur d'affectation =
Document& Document::operator=(const Document& other) {
    if (this != &other) { // Prevent self-assignment
        delete summary;   // Free the old memory
        name = other.name;
        author = other.author;
        summary = new string(*other.summary); // Deep copy
    }
    return *this;
}

// Destructeur
Document::~Document() {
    delete summary; // Release dynamically allocated memory
}

// Getters
string Document::getName() const {
    return name;
}

string Document::getAuthor() const {
    return author;
}

// Getter for summary
string Document::getSummary() const {
    return *summary;
}

// Display method
void Document::afficher() const {
    cout << "Nom: " << name << endl;
    cout << "Auteur: " << author << endl;
    cout << "Resume: " << *summary << endl;
}
