#include "Animal.h"

#ifndef Fish_H
#define Fish_H
class Fish :public Animal{
private:
	double weight;

public:
	Fish();

	void eat();

	virtual void sleep();
};
#endif // !Fish_H