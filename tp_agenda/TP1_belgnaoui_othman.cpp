//
// Created by othma on 22/10/2024.
//




#include <iostream>
#include <string>

using namespace std;

class Entree {
public:
    // Constructeur
    Entree(string nom, string numero) : m_nom(nom), m_numero(numero) {}

    // Methode pour afficher l'entree
    void afficher() const {
        cout << "Nom : " << m_nom << ", Numero : " << m_numero << endl;
    }

private:
    string m_nom;
    string m_numero;
};


void testEntree() {
    Entree e1("Alice", "0123456789");
    Entree e2("Bob", "0987654321");

    cout << "Test de la classe Entree :" << endl;
    e1.afficher();
    e2.afficher();
    cout << endl;
}



#include <iostream>
#include <string>
using namespace std;

class Tableau {
public:
    // Constructeur pour initialiser un tableau de taille donnee
    Tableau(int tailleMax) : m_tailleMax(tailleMax), m_nbelem(0) {
        m_entrees = new Entree*[m_tailleMax];
    }

    // Constructeur par copie
    Tableau(const Tableau& autre) {
        m_tailleMax = autre.m_tailleMax;
        m_nbelem = autre.m_nbelem;
        m_entrees = new Entree*[m_tailleMax];
        for (int i = 0; i < m_nbelem; ++i) {
            m_entrees[i] = new Entree(*autre.m_entrees[i]);  // Copier chaque entree
        }
    }

    // Operateur d'affectation
    Tableau& operator=(const Tableau& autre) {
        if (this != &autre) {
            // Liberer l'ancien tableau
            for (int i = 0; i < m_nbelem; ++i) {
                delete m_entrees[i];
            }
            delete[] m_entrees;

            // Copier le nouveau tableau
            m_tailleMax = autre.m_tailleMax;
            m_nbelem = autre.m_nbelem;
            m_entrees = new Entree*[m_tailleMax];
            for (int i = 0; i < m_nbelem; ++i) {
                m_entrees[i] = new Entree(*autre.m_entrees[i]);  // Copie profonde
            }
        }
        return *this;
    }

    // Destructeur pour liberer la memoire allouee
    ~Tableau() {
        for (int i = 0; i < m_nbelem; ++i) {
            delete m_entrees[i];
        }
        delete[] m_entrees;
    }

    // Methode pour ajouter une nouvelle entree
    void ajouter(Entree* nouvelleEntree) {
        if (m_nbelem < m_tailleMax) {
            m_entrees[m_nbelem] = nouvelleEntree;
            m_nbelem++;
        } else {
            cout << "Tableau plein, impossible d'ajouter une nouvelle entree." << endl;
        }
    }

    // Methode pour afficher toutes les entrees du tableau
    void afficher() const {
        for (int i = 0; i < m_nbelem; ++i) {
            m_entrees[i]->afficher();
        }
    }

    // Methode pour obtenir le nombre d'elements
    int getNbelem() const {
        return m_nbelem;
    }

    // Methode pour obtenir une entree à un index donne
    Entree* getEntree(int index) const {
        if (index >= 0 && index < m_nbelem) {
            return m_entrees[index];
        }
        return nullptr;  // Retourne nullptr si l'index est invalide
    }

    // Methode pour obtenir la taille maximale du tableau
    int getTailleMax() const {
        return m_tailleMax;
    }

private:
    int m_tailleMax;      // Taille maximale du tableau
    int m_nbelem;         // Nombre d'elements actuellement dans le tableau
    Entree** m_entrees;   // Pointeur vers un tableau d'entrees
};






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




class Agenda {
public:
    // Constructeur pour initialiser un agenda avec une taille donnee
    Agenda(int tailleMax) : m_tableau(new Tableau(tailleMax)) {}

    // Constructeur par copie
    Agenda(const Agenda& autre) {
        m_tableau = new Tableau(*autre.m_tableau);
    }

    // Operateur d'affectation
    Agenda& operator=(const Agenda& autre) {
        if (this != &autre) {
            delete m_tableau;
            m_tableau = new Tableau(*autre.m_tableau);
        }
        return *this;
    }

    // Destructeur pour liberer la memoire allouee au tableau
    ~Agenda() {
        cout << "Destruction de l'agenda" << endl;
        delete m_tableau;
    }


    // Methode pour ajouter une entree dans l'agenda
    void ajouter(string nom, string numero) {
        m_tableau->ajouter(new Entree(nom, numero));
    }

    // Methode pour afficher tout l'agenda
    void afficher() const {
        cout << "Contenu de l'agenda :" << endl;
        m_tableau->afficher();
    }

    // Methode pour concatener deux agendas
    void concat(Agenda &autreAgenda) {
        cout << "Concatenation de deux agendas." << endl;

        for (int i = 0; i < autreAgenda.m_tableau->getNbelem(); i++) {
            Entree* entree = autreAgenda.m_tableau->getEntree(i);
            if (entree != nullptr && m_tableau->getNbelem() < m_tableau->getTailleMax()) {
                m_tableau->ajouter(new Entree(*entree));  // Copie l'entree
            } else if (entree == nullptr) {
                cout << "Erreur : Pointeur d'entree invalide à l'index " << i << endl;
            } else {
                cout << "L'agenda est plein, impossible d'ajouter plus d'entrees." << endl;
                break;
            }
        }

        // Afficher le contenu de l'agenda apres concatenation
        cout << "Contenu de l'agenda apres concatenation :" << endl;
        m_tableau->afficher();
    }

private:
    Tableau* m_tableau;  // Pointeur vers un tableau contenant les entrees
};



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
