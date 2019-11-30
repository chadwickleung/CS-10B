//
//  fraction.h
//  a9
//
//  Created by Chadwick Leung on 4/3/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//
/*
 Chadwick Leung
 CS 10B
 4/1/19
 Dave Harden
 Assignment 9
 
 This is the file fraction.h.
 The fraction class can be used to create and store a fraction, which includes
 a numerator and a denominator. It can be used to add, multiply, subtract,
 divide and store the result in a simplified version.
 The following functions are available:
 
 Fraction();
 post: The calling object has been created and initialized as 0/1
 
 Fraction(int, int);
 post: The calling object has been created and initialized so that the numerator
 equals INnumerator and the denominator equals INdenominator
 
 Fraction addedTo(Fraction adder);
 post: Returns the sum of the two fractions
 
 Fraction subtract(Fraction subtracter);
 post: Returns the difference between the two fractions
 
 Fraction multipliedBy(Fraction multiplier) const;
 post: Returns the product of the two fractions
 
 Fraction dividedBy(Fraction divider);
 post: Returns the dividend of the two fractions
 
 void print() const;
 post: The calling object has been printed to the console window in the format
 numerator/denominator
 
 bool isEqualTo(Fraction target) const;
 post: Returns true if the two fractions equal each other
 
*/






#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
public:
    void print() const;
 
    Fraction addedTo(Fraction adder);
    Fraction subtract(Fraction subtracter);
    Fraction multipliedBy(Fraction multiplier) const;
    Fraction dividedBy(Fraction divider);
    Fraction();
    Fraction(int, int) ;
    
    bool isEqualTo(Fraction target) const;
    
private:
    int numerator;
    int denominator;
    void simplify(int &BIGnumerator, int &BIGdenominator) const;
};

#endif







//The result starts off at 0/1
//The product of 9/8 and 2/3 is 3/4
//The quotient of 9/8 and 2/3 is 27/16
//The sum of 9/8 and 2/3 is 43/24
//The difference of 9/8 and 2/3 is 11/24
//The two Fractions are not equal.
//The product of 3/2 and 2/3 is 1/1
