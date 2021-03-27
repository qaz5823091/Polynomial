#include "Polynomial.h"

#include <iostream>
#include <string>
#include <vector>

const int halfLength = 10;
const int length = halfLength * 2;

// constructor
Polynomial::Polynomial() {
	factors = new double[length];
	for (int i=0;i<length;i++) {
		factors[i] = 0;
	}
}

// copy constructor
Polynomial::Polynomial(const Polynomial &temp) {
	factors = new double[length];
	for (int i=0;i<length;i++) {
		factors[i] = temp.factors[i];
	}
}

// parametrized constructor
Polynomial::Polynomial(std::string poly) {
	factors = new double[length];
	for (int i=0;i<length;i++) {
		factors[i] = 0;
	}

    int pLength = poly.size();
	int tempLength;
	std::vector<int> v;

	if (poly[0] != '-')
		poly = '+' + poly;


	for (int i=0;i<pLength;i++) {
		if (poly[i] == ' ') {
			poly.erase(poly.begin() + i);
			i = i - 1;
			continue;
		}
		if (poly[i] == '+' || poly[i] == '-') {
			v.push_back(i);
			continue;
		}
	}
	v.push_back(pLength);
	
	pLength = v.size();
	std::string temp;
	double first;
	int second;
	std::string sub;
	for (int i=0;i<pLength-1;i++) {
		temp = poly.substr(v[i], v[i+1] - v[i]);
		tempLength = temp.size();
		for (int j=0;j<tempLength;j++) {
			if ( temp[j] == 'X' || temp[j] == 'x') {
				sub = temp.substr(0, j);
				first = std::stod(sub);
				sub = temp.substr(j+2, tempLength - j - 2);
				second = std::stoi(sub);
				factors[second] = first;
				break;
			}
		}
	}
}

// destructor
Polynomial::~Polynomial() {
	delete [] factors;
}

Polynomial Polynomial::operator=(Polynomial a) {
	for (int i=0;i<length;i++) {
		factors[i] = a.factors[i];
	}

	return *this;
}

Polynomial operator+(Polynomial a, Polynomial b) {
	Polynomial result = a;
	for (int i=0;i<length;i++) {
		result.factors[i] += b.factors[i];
	}

	return result;
}

Polynomial operator+(Polynomial a, double b) {
	Polynomial result;

	result = a;
	result.factors[0] += b;

	return result;
}

Polynomial operator+(double a, Polynomial b) {
	Polynomial result;

	result = b;
	result.factors[0] += a;

	return result;
}

Polynomial operator-(Polynomial a, Polynomial b) {
	Polynomial result;
	for (int i=0;i<length;i++) {
		result.factors[i] = a.factors[i] - b.factors[i];
	}

	return result;
}

Polynomial operator-(Polynomial a, double b) {
	Polynomial result;

	result = a;
	result.factors[0] -= b;

	return result;
}

Polynomial operator-(double a, Polynomial b) {
	Polynomial result;
	result = (-1) * b;
	result.factors[0] += a;
	
	return result;
}

Polynomial operator*(Polynomial a, Polynomial b) {
	Polynomial result;
	for (int i=0;i<halfLength;i++) {
		for (int j=0;j<halfLength;j++) {
			result.factors[i+j] += a.factors[i] * b.factors[j];
		}
	}

	return result;
}

Polynomial operator*(Polynomial a, double b) {
	Polynomial result;
	for (int i=0;i<length;i++) {
		result.factors[i] = b * a.factors[i];
	}

	return result;
}

Polynomial operator*(double a, Polynomial b) {
	Polynomial result;
	for (int i=0;i<length;i++) {
		result.factors[i] = a * b.factors[i];
	}

	return result;
}

std::string Polynomial::getPolynomial() {
	std::string result;
	bool first = true;
	for (int i=length-1;i>=0;i--) {
		if (factors[i] == 0)
			continue;

		if (factors[i] > 0)
			result += '+';
		result += std::to_string(factors[i]) + "X^" + char(i + '0');
	}

	return result;
}

void Polynomial::print() {
	std::cout<<getPolynomial()<<"\n";
	/*
	for (int i=0;i<length;i++)
		std::cout<<factors[i]<<" ";

	std::cout<<'\n';
	*/
}