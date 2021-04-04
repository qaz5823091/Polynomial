#include "Polynomial.h"
#include <iostream>
// #include <typeinfo>

int main() {
	Polynomial f("3.1x^2 +2x^100 + 3x^0"), g("2X^2 + 1X^1 + 10X^0"), h;
	Polynomial f2(f);

	f = g;
	f.print();
	f.integral();
	f.print();
	g.integral();
	g.print();
}
