#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;
class Complex{
  private:
    float real; // real part of the complex number
    float imaginary; // imaginary part of the complex number
  public:
    Complex(){
      real = 0; // set the real part to 0
      imaginary = 0; // set the imaginary part to 0
    }
    Complex(float r, float i){
      real = r; // set the real part to the value of r
      imaginary = i; // set the imaginary part to the value of i
    }
    float getReal() const { return real; } // get the real part of the complex number
    float getImaginary() const { return imaginary; } // get the imaginary part of the complex number
    
    Complex operator+(Complex rhs){
      return Complex(real + rhs.real, imaginary + rhs.imaginary); // add the real and imaginary parts of the two complex numbers
    }
    Complex operator-(Complex rhs){
      return Complex(real - rhs.real, imaginary - rhs.imaginary); // subtract the real and imaginary parts of the two complex numbers
    }
    Complex operator*(const Complex& other) const {
      return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real); // multiply the two complex numbers
    }
    Complex operator/(const Complex& other) const {
      float denominator = other.real * other.real + other.imaginary * other.imaginary; // calculate the denominator
      return Complex((real * other.real + imaginary * other.imaginary) / denominator, (imaginary * other.real - real * other.imaginary) / denominator); // calculate the numerator
    }
    Complex conjugate() {
      return Complex(real, -imaginary); // return the conjugate of the complex number
    }
};

#endif
