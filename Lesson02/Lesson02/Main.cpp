#include "Animal.h"
#include "Fish.h"

void main(){
	Animal animal(50);
	Fish fish;
	animal.eat();
	animal.sleep();
	fish.eat();
	fish.sleep();
}