#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
  private:
    double *factors;
  
  public:
    Polynomial();
    Polynomial(std::string);
    ~Polynomial();
    Polynomial operator=(const Polynomial &);
    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);
    Polynomial operator*(const Polynomial &);
    static int length;
    std::string getPolynomial();
    void print();
};

#endif