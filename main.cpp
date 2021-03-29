#include "Polynomial.h"
#include <iostream>
// #include <typeinfo>

int main() {
	Polynomial f("3x^100+2x^10+3x^0"), g("2X^2 + 1X^1 + 10X^0"), h;
	Polynomial f2(f);

	f.differential();
	f.print();
	g.differential();
	g.print();
}
