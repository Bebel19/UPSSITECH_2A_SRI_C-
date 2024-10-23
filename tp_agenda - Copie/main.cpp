//
// Created by othma on 22/10/2024.
//
#include <iostream>
#include "Agenda.h"

using namespace std;

int main() {
    Agenda monAgenda(10);
    monAgenda.ajouter("Alice", "12345");
    monAgenda.ajouter("Bob", "67890");
    monAgenda.afficher();

    monAgenda.supprimer("Alice");
    monAgenda.afficher();

    return 0;
}

