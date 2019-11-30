//
//  fraction.h
//  a11
//
//  Created by Chadwick Leung on 4/12/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Chadwick Leung
 CS 10B
 4/12/19
 Dave Harden
 Assignment 11
 
 This is the file fraction.h.
 The fraction class can be used to create and store a fraction, which includes
 a numerator and a denominator. It can be used to add, multiply, subtract,
 divide and store the result in a simplified version using simple operators
 after overloading the operators.
 The following functions are available:
 
 Fraction(int inNumer = 0, int inDenom = 1);
 post: The calling object has been created and initialized so that the numerator
 equals inNumer and the denominator equals inDenom. If there is only one input,
 then the denominator is set to be 1 by default, if there is no input, the
 numerator and denominator are set to be 0 and 1 respectively
 
 friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
 pre : an object has been stored in right
 post: insert the object right to the stream out
 
 friend std::istream& operator>>(std::istream& in, Fraction& right);
 pre : a Fraction object is being input
 post: extract the value of the object to the stream in
 
 friend Fraction operator+(const Fraction& left, const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
       or a integer
 post: return the simplified version of the sum of the two objects after
       overloading the operator+
 
 friend Fraction operator-(const Fraction& left, const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the simplified version of the difference of the two objects after
 overloading the operator-
 
 friend Fraction operator*(const Fraction& left, const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the simplified version of the product of the two objects after
 overloading the operator*
 
 friend Fraction operator/(const Fraction& left, const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the simplified version of the quotient of the two objects after
 overloading the operator/
 
 Fraction operator+=(const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the calling object's new value, which is the sum of its orgininal
 value and the value in the 'right' object
 
 Fraction operator-=(const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the calling object's new value, which is the difference between its
 orgininal value and the value in the 'right' object
 
 Fraction operator*=(const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the calling object's new value, which is the product of its orgininal
 value and the value in the 'right' object (initial*object)
 
 Fraction operator/=(const Fraction& right);
 pre : either side of the calling object has a value assigned, either a fraction
 or a integer
 post: return the calling object's new value, which is the quotient
 of its orgininal value and the value in the 'right' object (initial/right)
 
 Fraction operator++();
 pre : the calling object has a value assigned to it already
 post: return the incremented value (increment by 1) of the calling object,
 this is a pre increment
 
 Fraction operator++(int);
 pre : the calling object has a value assigned to it already
 post: return the original value of the calling object, and then increment its
 value by 1, this is a post inrement
 
 Fraction operator--();
 pre : the calling object has a value assigned to it already
 post: return the decremented value (decrement by 1) of the calling object,
 this is a pre decrement
 
 Fraction operator--(int);
 pre : the calling object has a value assigned to it already
 post: return the original value of the calling object, and then decrement its
 value by 1, this is a post decrement
 
 friend bool operator<(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is smaller than right,
 return false if otherwise
 
 friend bool operator<=(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is smaller than or equal to right,
 return false if otherwise
 
 friend bool operator>(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is greater than right,
 return false if otherwise
 
 friend bool operator>=(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is greater than or equal to right,
 return false if otherwise
 
 friend bool operator==(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is equal to right,
 return false if otherwise
 
 friend bool operator!=(const Fraction& left, const Fraction& right);
 pre : both sides have a value assigned, either a integer or a fraction
 post: return a true bool value if left is NOT equal to right,
 return false if otherwise
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_fraction{
    class Fraction{
    public:
        Fraction(int inNumer = 0, int inDenom = 1);
        
        friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
        friend std::istream& operator>>(std::istream& in, Fraction& right);
        
        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);
        
        Fraction operator+=(const Fraction& right);
        Fraction operator-=(const Fraction& right);
        Fraction operator*=(const Fraction& right);
        Fraction operator/=(const Fraction& right);
        
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        
    private:
        int numerator;
        int denominator;
        void simplify();
        
    };
    
}


#endif







//----- Testing basic Fraction creation & printing
//(Fractions should be in reduced form, and as mixed numbers.)
//Fraction [0] = 1/2
//Fraction [1] = -5/7
//Fraction [2] = 10
//Fraction [3] = -4
//Fraction [4] = 0
//Fraction [5] = 4+2/3
//Fraction [6] = 0
//
//----- Now reading Fractions from file
//Read Fraction = 1/3
//Read Fraction = 1/2
//Read Fraction = 3/4
//Read Fraction = -4/5
//Read Fraction = 6
//Read Fraction = 5
//Read Fraction = -8
//Read Fraction = 1+2/5
//Read Fraction = -16+2/3
//Read Fraction = 1+1/4
//Read Fraction = 2
//Read Fraction = -4+1/4
//Read Fraction = -10+5/6
//
//----- Testing relational operators between Fractions
//Comparing 1/2 to 1/2
//Is left < right? false
//Is left <= right? true
//Is left > right? false
//Is left >= right? true
//Does left == right? true
//Does left != right ? false
//Comparing 1/2 to -1/2
//Is left < right? false
//Is left <= right? false
//Is left > right? true
//Is left >= right? true
//Does left == right? false
//Does left != right ? true
//Comparing -1/2 to 1/10
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//Comparing 1/10 to 0
//Is left < right? false
//Is left <= right? false
//Is left > right? true
//Is left >= right? true
//Does left == right? false
//Does left != right ? true
//Comparing 0 to 0
//Is left < right? false
//Is left <= right? true
//Is left > right? false
//Is left >= right? true
//Does left == right? true
//Does left != right ? false
//
//----- Testing relations between Fractions and integers
//Comparing -1/2 to 2
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//Comparing -3 to 1/4
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//
//----- Testing binary arithmetic between Fractions
//1/6 + 1/3 = 1/2
//1/6 - 1/3 = -1/6
//1/6 * 1/3 = 1/18
//1/6 / 1/3 = 1/2
//1/3 + -2/3 = -1/3
//1/3 - -2/3 = 1
//1/3 * -2/3 = -2/9
//1/3 / -2/3 = -1/2
//-2/3 + 5 = 4+1/3
//-2/3 - 5 = -5+2/3
//-2/3 * 5 = -3+1/3
//-2/3 / 5 = -2/15
//5 + -1+1/3 = 3+2/3
//5 - -1+1/3 = 6+1/3
//5 * -1+1/3 = -6+2/3
//5 / -1+1/3 = -3+3/4
//
//----- Testing arithmetic between Fractions and integers
//-1/2 + 4 = 3+1/2
//-1/2 - 4 = -4+1/2
//-1/2 * 4 = -2
//-1/2 / 4 = -1/8
//3 + -1/2 = 2+1/2
//3 - -1/2 = 3+1/2
//3 * -1/2 = -1+1/2
//3 / -1/2 = -6
//
//----- Testing shorthand arithmetic assignment on Fractions
//1/6 += 4 = 4+1/6
//4+1/6 -= 4 = 1/6
//1/6 *= 4 = 2/3
//2/3 /= 4 = 1/6
//4 += -1/2 = 3+1/2
//3+1/2 -= -1/2 = 4
//4 *= -1/2 = -2
//-2 /= -1/2 = 4
//-1/2 += 5 = 4+1/2
//4+1/2 -= 5 = -1/2
//-1/2 *= 5 = -2+1/2
//-2+1/2 /= 5 = -1/2
//
//----- Testing shorthand arithmetic assignment using integers
//-1/3 += 3 = 2+2/3
//2+2/3 -= 3 = -1/3
//-1/3 *= 3 = -1
//-1 /= 3 = -1/3
//
//----- Testing increment/decrement prefix and postfix
//Now g = -1/3
//g++ = -1/3
//Now g = 2/3
//++g = 1+2/3
//Now g = 1+2/3
//g-- = 1+2/3
//Now g = 2/3
//--g = -1/3
//Now g = -1/3
