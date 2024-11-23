//
// Created by othma on 23/11/2024.
//

#include "Document.h"
#include <iostream>
using namespace std;

int main() {
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

    return 0;
}
