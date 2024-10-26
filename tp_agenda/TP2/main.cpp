// main.cpp
#include "Entree.h"
#include "Tableau.h"
#include "Agenda.h"
#include <iostream>
using namespace std;

void testEntree() {
    cout << "===== Test de la classe Entree =====" << endl;
    Entree e1("Alice", "0123456789");
    Entree e2("Bob", "0987654321");

    cout << "Test de la classe Entree :" << endl;
    e1.afficher();
    e2.afficher();
    cout << endl;
}


void testTableau() {
    cout << "===== Test de la classe Tableau =====" << endl;
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
    cout << "===== Test du constructeur par copie de la classe Tableau =====" << endl;
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
    cout << endl;
}



void testAgenda() {
    cout << "===== Test de la classe Agenda =====" << endl;
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
    cout << "===== Test du constructeur par copie de la classe Agenda =====" << endl;
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
    cout << endl;
}
// Tests des operateurs surcharges de la classe Agenda

void testOperateurPlusEgal() {
    cout << "===== Test de l'operateur += =====" << endl;
    Agenda agenda(3);
    agenda += Entree("Alice", "0123456789");
    agenda += Entree("Bob", "0987654321");

    cout << "Test de l'operateur += :" << endl;
    agenda.afficher();
    cout << endl;
}

void testOperateurPlus() {
    cout << "===== Test de l'operateur + =====" << endl;
    Agenda agenda1(3);
    agenda1 += Entree("Alice", "0123456789");
    Agenda agenda2(3);
    agenda2 += Entree("Bob", "0987654321");

    Agenda agenda3 = agenda1 + agenda2;  // Concatenation

    cout << "Test de l'operateur + :" << endl;
    agenda3.afficher();
    cout << endl;
}

void testOperateurCrochet() {
    cout << "===== Test de l'operateur [] =====" << endl;
    Agenda agenda(3);
    agenda += Entree("Alice", "0123456789");
    agenda += Entree("Bob", "0987654321");

    Entree* entree = agenda["Alice"];
    if (entree != nullptr) {
        cout << "Entree trouvee : ";
        entree->afficher();
    } else {
        cout << "Entree non trouvee." << endl;
    }
    cout << endl;
}

void testOperateurMoinsEgal() {
    cout << "===== Test de l'operateur -= =====" << endl;
    Agenda agenda(3);
    agenda += Entree("Alice", "0123456789");
    agenda += Entree("Bob", "0987654321");
    agenda += Entree("Alice", "9999999999");

    cout << "Avant suppression :" << endl;
    agenda.afficher();

    agenda -= "Alice";  // Supprime toutes les occurrences d'Alice

    cout << "Apres suppression :" << endl;
    agenda.afficher();
    cout << endl;
}

void testOperateurEgalEgal() {
    cout << "===== Test de l'operateur == =====" << endl;
    Agenda agenda1(3), agenda2(3);
    agenda1 += Entree("Alice", "0123456789");
    agenda2 += Entree("Alice", "0123456789");

    if (agenda1 == agenda2) {
        cout << "Les deux agendas sont identiques." << endl;
    } else {
        cout << "Les deux agendas sont differents." << endl;
    }
    cout << endl;
}

void testOperateurSlash() {
    cout << "===== Test de l'operateur / =====" << endl;
    Agenda agenda(3);
    agenda += Entree("Alice", "0123456789");

    if (agenda / "Alice") {
        cout << "Alice est present dans l'agenda." << endl;
    } else {
        cout << "Alice n'est pas present dans l'agenda." << endl;
    }
    cout << endl;
}

void testOperateurParentheses() {
    cout << "===== Test de l'operateur () =====" << endl;
    Agenda agenda(3);
    agenda += Entree("Alice", "0123456789");
    agenda += Entree("Bob", "0987654321");
    agenda += Entree("Charlie", "1234567890");

    cout << "Entrees commencant par 'A' :" << endl;
    agenda('A');
    cout << endl;
}

int main() {
    testEntree();
    testTableau();
    testAgenda();

    // Test du constructeur par copie et de l'operateur d'affectation
    testConstructeurParCopieAgenda();
    testConstructeurParCopieTableau();

    // Tests des operateurs surcharges
    testOperateurPlusEgal();
    testOperateurPlus();
    testOperateurCrochet();
    testOperateurMoinsEgal();
    testOperateurEgalEgal();
    testOperateurSlash();
    testOperateurParentheses();
    return 0;
}

