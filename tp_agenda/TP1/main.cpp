#include <iostream>
#include <string>
using namespace std;

#include "Entree.h"
#include "Tableau.h"
#include "Agenda.h"

void testEntree() {
    Entree e1("Alice", "0123456789");
    Entree e2("Bob", "0987654321");

    cout << "Test de la classe Entree :" << endl;
    e1.afficher();
    e2.afficher();
    cout << endl;
}

void testTableau() {
    // Creation d'un tableau de 3 entrees maximum
    Tableau tableau(3);

    cout << "Test de la classe Tableau :" << endl;


    // Creation et ajout d'entrees
    tableau.ajouter(new Entree("Alice", "0123456789"));
    tableau.ajouter(new Entree("Bob", "0987654321"));
    tableau.ajouter(new Entree("Charlie", "1234567890"));

    cout << "Contenu du tableau :" << endl;
    tableau.afficher();

    // Essayer d'ajouter une entree supplementaire (devrait echouer)
    tableau.ajouter(new Entree("David", "9876543210"));
    cout << endl;
}


void testConstructeurParCopieTableau() {
    // Creation d'un tableau initial avec 3 entrees
    Tableau tableau1(3);
    tableau1.ajouter(new Entree("Alice", "0123456789"));
    tableau1.ajouter(new Entree("Bob", "0987654321"));

    // Utilisation du constructeur par copie pour dupliquer tableau1
    Tableau tableau2 = tableau1;

    // Affichage des deux tableaux pour verifier qu'ils sont identiques mais independants
    cout << "Tableau 1 :" << endl;
    tableau1.afficher();
    cout << "Tableau 2 (copie) :" << endl;
    tableau2.afficher();

    // Modification du deuxieme tableau pour s'assurer que les objets sont independants
    tableau2.ajouter(new Entree("Charlie", "1234567890"));

    cout << "Tableau 1 apres modification de tableau 2 :" << endl;
    tableau1.afficher();
    cout << "Tableau 2 apres modification :" << endl;
    tableau2.afficher();
}



void testAgenda() {
    Agenda agenda(5);  // Creation d'un agenda avec 5 entrees maximum

    // Ajout de quelques entrees dans l'agenda
    agenda.ajouter("Alice", "0123456789");
    agenda.ajouter("Bob", "0987654321");

    cout << "Test de l'agenda :" << endl;
    agenda.afficher();

    // Test de la concatenation avec un autre agenda
    Agenda autreAgenda(3);
    autreAgenda.ajouter("Charlie", "1234567890");
    autreAgenda.ajouter("David", "9876543210");

    agenda.concat(autreAgenda);
    cout << endl;
}


void testConstructeurParCopieAgenda() {
    Agenda agenda1(3);
    agenda1.ajouter("Alice", "0123456789");
    agenda1.ajouter("Bob", "0987654321");

    // Utilisation du constructeur par copie
    Agenda agenda2 = agenda1;

    // Affichage des deux agendas pour verifier qu'ils sont identiques mais independants
    cout << "Agenda 1 :" << endl;
    agenda1.afficher();
    cout << "Agenda 2 (copie) :" << endl;
    agenda2.afficher();

    // Modification d'un agenda pour verifier qu'ils sont independants
    agenda2.ajouter("Charlie", "1234567890");
    cout << "Agenda 1 apres modification de l'agenda 2 :" << endl;
    agenda1.afficher();
    cout << "Agenda 2 apres modification :" << endl;
    agenda2.afficher();
}


int main() {
    testEntree();
    testTableau();
    testAgenda();

    // Test du constructeur par copie et de l'operateur d'affectation
    testConstructeurParCopieAgenda();
    testConstructeurParCopieTableau();
    return 0;
}