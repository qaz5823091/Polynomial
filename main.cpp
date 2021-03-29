#include "Polynomial.h"
#include <iostream>
#include <typeinfo>

int main() {
	Polynomial f("3X^10 + 5X^1 + 7X^0"), g("2X^2 + 1X^1 + 10X^0"), h;
	
	//f.print();
	f.print();
	f.integral();
	f.print();
	f.differential();
	f.print();
	
}