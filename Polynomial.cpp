#include "Polynomial.h"

#include <iostream>
#include <vector>

int Polynomial::length = 10;

Polynomial::Polynomial() {
  factors = new double[length];
  for (int i=0;i<length;i++) {
    factors[i] = 0;
  }
}

Polynomial::Polynomial(std::string poly) {
    int length = poly.size();
	std::vector<int> v;
	for (int i=0;i<length;i++) {
		if (poly[i] == '+' || poly[i] == '-') {
			v.push_back(i);
			continue;
		}
	}
}

Polynomial::~Polynomial() {
  delete [] factors;
}

std::string Polynomial::getPolynomial() {
  std::string result;
  bool first = true;
  for (int i=length-1;i>0;i--) {
    
  return result;
}

void Polynomial::print() {
  std::cout<<getPolynomial()<<"\n";
}