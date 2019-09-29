#include "Fish.h"
#include <iostream>
using namespace std;

Fish::Fish() :Animal(70){
	weight = 60;
}

void Fish::eat(){
	cout << "Fish eat" << endl;
}

void Fish::sleep(){
	cout << "Fish sleep" << endl;
}