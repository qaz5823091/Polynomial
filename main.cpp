#include "Polynomial.h"
#include <iostream>
#include <typeinfo>

int main() {
	Polynomial f("3X^2 + 5X^1 + 7X^0"), g("2X^2 + 1X^1 + 10X^0"), h;

	g = f + g;
	(g).print();
	
}