#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial {
	private:
		std::vector<double> factors;

	public:
		Polynomial();
		Polynomial(const Polynomial &);
		Polynomial(std::string);
		~Polynomial();

		Polynomial operator=(const Polynomial &);

		friend Polynomial operator+(const Polynomial & , const Polynomial & );
		friend Polynomial operator+(const Polynomial & , double);
		friend Polynomial operator+(double, const Polynomial &);

		friend Polynomial operator-(const Polynomial & , const Polynomial & );
		friend Polynomial operator-(const Polynomial & , double);
		friend Polynomial operator-(double, const Polynomial & );

		friend Polynomial operator*(const Polynomial & , const Polynomial & );
		friend Polynomial operator*(const Polynomial & , double);
		friend Polynomial operator*(double, const Polynomial & );

		void differential();
		void integral();

		std::string getPolynomial();
		void print();
};

#endif
