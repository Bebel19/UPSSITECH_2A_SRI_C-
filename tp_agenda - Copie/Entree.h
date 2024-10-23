//
// Created by othma on 22/10/2024.
//

#ifndef ENTREE_H
#define ENTREE_H

#include <string>
using namespace std;
#include <iostream>

class Entree {
public:
  //Constructeur
  Entree(string name,int number) : name(name), number(number) {};

  //Methodes
  //getters
  string getName(){return name;}
  int getNumber(){return number;}
  //setters

  //Others
  void show(){
    cout << "Name : " << name << "number : " << number << endl;
  }



private:
  //Attributs
  string name;
  int number;
};



#endif //ENTREE_H
