#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal(double weight){
	this->weight = weight;
}

void Animal::eat(){
	cout << "Animal eat" << endl;
}

void Animal::sleep(){
	cout << "Animal sleep" << endl;
}