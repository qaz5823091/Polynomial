#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
	private:
		double *factors;

	public:
		Polynomial();
		Polynomial(const Polynomial &);
		Polynomial(std::string);
		~Polynomial();

		Polynomial operator=(Polynomial );

		friend Polynomial operator+(Polynomial , Polynomial );
		friend Polynomial operator+(Polynomial , double);
		friend Polynomial operator+(double, Polynomial );

		friend Polynomial operator-(Polynomial , Polynomial );
		friend Polynomial operator-(Polynomial , double);
		friend Polynomial operator-(double, Polynomial );

		friend Polynomial operator*(Polynomial , Polynomial );
		friend Polynomial operator*(Polynomial , double);
		friend Polynomial operator*(double, Polynomial );

		std::string getPolynomial();
		void print();
};

#endif