//
// Created by othma on 23/11/2024.
//

#include "Document.h"
#include <iostream>
#include "Livre.h"
using namespace std;

int main() {
    //Test document :
    // Creation d'un document
    Document doc1("Titre1", "Auteur1", "Ceci est un resume.");
    cout << "Affichage de Document 1:" << endl;
    doc1.afficher();
    cout << endl;

    // Test du constructeur par copie
    Document doc2 = doc1;
    cout << "Affichage de Document 2 (copie de Document 1):" << endl;
    doc2.afficher();
    cout << endl;

    // Test de l'operateur d'affectation
    Document doc3("Temp", "Temp", "Resume temporaire.");
    doc3 = doc1;
    cout << "Affichage de Document 3 (apres affectation de Document 1):" << endl;
    doc3.afficher();
    cout << endl;


    // Test Livre : Creation d'un Livre et affichage
    Livre livre1("Programmation C++", "Bjarne Stroustrup", "Un guide complet pour apprendre le C++.",
                 "Addison-Wesley", 2013);

    cout << "Affichage du Livre 1:" << endl;
    livre1.afficher();
    cout << endl;

    // Test 2 : Utilisation du constructeur par copie (herite de Document)
    Livre livre2 = livre1;

    cout << "Affichage du Livre 2 (copie de Livre 1):" << endl;
    livre2.afficher();
    cout << endl;

    return 0;
}
