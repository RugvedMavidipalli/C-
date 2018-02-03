#ifndef COMPLEX_H
#define COMPLEX_H

// Author: Fill name in here
// Source File: myComplex.h
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class myComplex {
public:
  myComplex();
  myComplex(double in_real);
  myComplex(double in_real, double in_imaginary);

  void setReal(const double in_real);
  void setImaginary(const double in_imaginary);
  void setComplex(const double in_real, const double in_imaginary);
  
  double getReal() const;
  double getImaginary() const;
  double getMagnitude() const;
  double getAngle() const;
  
  void displayPolar() const;
  string display() const;

  myComplex conjugate();
  myComplex addition(const myComplex right);
  myComplex subtraction(const myComplex right);
  myComplex multiplication(const myComplex right);
  myComplex division(const myComplex right);
  
  myComplex operator+ (const myComplex& right);
  myComplex operator- (const myComplex& right);
  myComplex operator* (const myComplex& right);
  myComplex operator/ (const myComplex& right);

  bool operator== (const myComplex& right);
  bool operator!= (const myComplex& right);

 
  friend ostream & operator<<( ostream& output,const myComplex &thing );
  friend istream & operator>>( istream &input, myComplex &thing );

private:
  double real;
  double imaginary;
};
#endif
