#include "Polynomial.h"

#include <iostream>
#include <string>
#include <vector>

// constructor
Polynomial::Polynomial() {

}

// copy constructor
Polynomial::Polynomial(const Polynomial &temp) {
	factors = temp.factors;
}

// parametrized constructor
Polynomial::Polynomial(std::string poly) {
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
	v.push_back(poly.size());

	pLength = v.size();
	std::string temp;
	double first;
	int second;
	std::string sub;
	int maxSize = 0;
	for (int i=0;i<pLength-1;i++) {
		temp = poly.substr(v[i], v[i+1] - v[i]);
		tempLength = temp.size();
		for (int j=0;j<tempLength;j++) {
			if ( temp[j] == 'X' || temp[j] == 'x') {
				sub = temp.substr(j+2, tempLength - j - 2);
				second = std::stoi(sub);
				if (second > maxSize) {
                    maxSize = second;
                    break;
				}
			}
		}
	}
	std::vector<double> tempFactors(maxSize+1, 0);
	for (int i=0;i<pLength-1;i++) {
		temp = poly.substr(v[i], v[i+1] - v[i]);
		tempLength = temp.size();
		for (int j=0;j<tempLength;j++) {
			if ( temp[j] == 'X' || temp[j] == 'x') {
				sub = temp.substr(0, j);
				first = std::stod(sub);
				sub = temp.substr(j+2, tempLength - j - 2);
				second = std::stoi(sub);
				tempFactors[second] = first;
				break;
			}
		}
	}
	factors = tempFactors;
}

// destructor
Polynomial::~Polynomial() {
	factors.erase(factors.begin(), factors.begin() + factors.size());
}

Polynomial Polynomial::operator=(const Polynomial &a) {
	factors = a.factors;

	return *this;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
	Polynomial result;
	int aLength = a.factors.size();
	int bLength = b.factors.size();
	int length = (aLength > bLength) ? aLength : bLength;
	std::vector<double> temp(length, 0);
	for (int i=0;i<aLength;i++) {
		temp[i] += a.factors[i];
	}
	for (int i=0;i<bLength;i++) {
		temp[i] += b.factors[i];
	}
	result.factors = temp;

	return result;
}

Polynomial operator+(const Polynomial &a, double b) {
	Polynomial result;

	result = a;
	result.factors[0] += b;

	return result;
}

Polynomial operator+(double a, const Polynomial &b) {
	Polynomial result;

	result = b;
	result.factors[0] += a;

	return result;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
	Polynomial result;
	int aLength = a.factors.size();
	int bLength = b.factors.size();
	int length = (aLength > bLength) ? aLength : bLength;
	std::vector<double> temp(length, 0);
	for (int i=0;i<aLength;i++) {
		temp[i] += a.factors[i];
	}
	for (int i=0;i<bLength;i++) {
        temp[i] -= b.factors[i];
	}
	result.factors = temp;

	return result;
}

Polynomial operator-(const Polynomial &a, double b) {
	Polynomial result;

	result = a;
	result.factors[0] -= b;

	return result;
}

Polynomial operator-(double a, const Polynomial &b) {
	Polynomial result;
	result = (-1) * b;
	result.factors[0] += a;

	return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
	Polynomial result;
	int aLength = a.factors.size();
	int bLength = b.factors.size();
	int length = a.factors.size() + b.factors.size();
	std::vector<double> temp(length, 0);
	for (int i=0;i<aLength;i++) {
		for (int j=0;j<bLength;j++) {
			temp[i+j] += a.factors[i] * b.factors[j];
		}
	}
	result.factors = temp;

	return result;
}

Polynomial operator*(const Polynomial &a, double b) {
	Polynomial result = a;
	int length = a.factors.size();
	for (int i=0;i<length;i++) {
		result.factors[i] = b * a.factors[i];
	}

	return result;
}

Polynomial operator*(double a, const Polynomial &b) {
	Polynomial result = b;
	int length = b.factors.size();
	for (int i=0;i<length;i++) {
		result.factors[i] = a * b.factors[i];
	}

	return result;
}

void Polynomial::integral(){
    int length = factors.size();
    factors.push_back(factors[length - 1] * (1.0 / length) );
	for(int i=length-1; i>=0; i--){
		if(int(factors[i]) == 0)
			continue;

		factors[i+1]=factors[i]*(1.0/(1+i));
	}
	factors[0]=0;
}

void Polynomial::differential(){
    int length = factors.size();
	for(int i=0;i<length;i++){
		factors[i] = factors[i+1] * (i+1);
	}
	factors.erase(factors.begin() + length - 1);
}

std::string Polynomial::getPolynomial() {
	std::string result;
	bool first = true;
	int length = factors.size();
	for (int i=length-1;i>=0;i--) {
		if (factors[i] == 0)
			continue;

		if (factors[i] > 0) {
			if (first)
				first = false;
			else
				result += '+';
		}
		result += std::to_string(factors[i]) + "X^" + std::to_string(i);
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
