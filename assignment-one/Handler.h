#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Complex.h"
using namespace std;

class Handler{
    private:
        static Complex parseComplex(const string &input)
        {
            size_t iPos = input.find("i"); // find the position of 'i'
            if (iPos == string::npos || iPos == 0 || iPos == input.size() - 1)
            {
                throw invalid_argument("Invalid complex number format"); // throw an error if the format is invalid
            }

            float real = stof(input.substr(0, iPos - 1)); // real part up to operator before 'i'
            char sign = input[iPos - 1]; // sign before 'i'
            if (sign != '+' && sign != '-')
            {
                throw invalid_argument("Missing + or - before imaginary part"); // throw an error if the sign is invalid
            }

            float imag = stof(input.substr(iPos + 1)); // imaginary part after 'i'
            if (sign == '-')
                imag = -imag; // if the sign is '-' then the imaginary part is negative

            return Complex(real, imag);
        }

    public:
        static int print_and_get_choices(){
            int choice;
            cout << "Please choose one of the following options: " << endl;
            cout << "(1) Add" << endl;
            cout << "(2) Subtract" << endl;
            cout << "(3) Multiply" << endl;
            cout << "(4) Divide" << endl;
            cout << "(5) Find Conjugate" << endl;
            cout << "(6) Quit" << endl;
            cout << "============================================" << endl;
            cout << "What is your choice (Please enter a number): "; cin >> choice;
            
            
            return choice;
        }
        static void add_two_complex_numbers(){
            string input;
            cout << "Adding two complex numbers:" << endl;
            cout << "============================================" << endl;
            cout << "Enter the first number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex a = parseComplex(input);
            
            cout << "Enter the second number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex b = parseComplex(input);
            
            Complex result = a + b;
            cout << "The result is: " << result.getReal() << (result.getImaginary() >= 0 ? "+i" : "-i") << abs(result.getImaginary()) << endl; // get and print real and imaginary parts with proper signs
        }
        static void subtract_two_complex_numbers(){
            string input;
            cout << "Subtracting two complex numbers:" << endl;
            cout << "============================================" << endl;
            cout << "Enter the first number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex a = parseComplex(input);
            
            cout << "Enter the second number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex b = parseComplex(input);
            
            Complex result = a - b;
            cout << "The result is: " << result.getReal() << (result.getImaginary() >= 0 ? "+i" : "-i") << abs(result.getImaginary()) << endl; 
        }
        static void multiply_two_complex_numbers(){
            string input;
            cout << "Multiplying two complex numbers:" << endl;
            cout << "============================================" << endl;
            cout << "Enter the first number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex a = parseComplex(input);
            
            cout << "Enter the second number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex b = parseComplex(input);
            
            Complex result = a * b;
            cout << "The result is: " << result.getReal() << (result.getImaginary() >= 0 ? "+i" : "-i") << abs(result.getImaginary()) << endl; 
        }
        static void divide_two_complex_numbers(){
            cout << "Dividing two complex numbers:" << endl;
            cout << "============================================" << endl;
            string input;
            cout << "Enter the first number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex a = parseComplex(input);
            
            cout << "Enter the second number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex b = parseComplex(input);
            
            Complex result = a / b;
            cout << "The result is: " << result.getReal() << (result.getImaginary() >= 0 ? "+i" : "-i") << abs(result.getImaginary()) << endl; 
        }
        static void find_conjugate_of_a_complex_number(){
            cout << "Find Conjugate of a complex number:" << endl;
            cout << "============================================" << endl;
            string input;
            cout << "Enter the first number in the form a+ib or a-ib (for example: 2+i3 or 2-i3): " << endl;
            cin >> input;
            Complex a = parseComplex(input);
            
            
            Complex result = a.conjugate();
            cout << "The result is: " << result.getReal() << (result.getImaginary() >= 0 ? "+i" : "-i") << abs(result.getImaginary()) << endl; 
        }
};

#endif
