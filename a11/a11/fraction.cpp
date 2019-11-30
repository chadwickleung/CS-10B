//
//  fraction.cpp
//  a11
//
//  Created by Chadwick Leung on 4/12/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Class invariant:
 A Fraction object has 2 int data member:
 numerator, which stores the numerator assigned,
 denominator, which stores the denominator assigned.
 After using the simplify function, the fractions would be stored as
 a simplified version with the same value
 */

#include <iostream>
#include <cassert>
#include "fraction.h"
#include <string>

using namespace std;

namespace cs_fraction
{
    Fraction::Fraction(int inNumer, int inDenom)
    {
        assert(inDenom != 0);
        
        
        numerator = inNumer;
        
        denominator = inDenom;
    }
    
    
    
    
    
    ostream& operator<<(ostream& out, const Fraction& right)
    {
        Fraction tosimplify(right.numerator, right.denominator);
        
        tosimplify.simplify();
    
        
        if (tosimplify.numerator == 0 || tosimplify.denominator == 1)
        {
            out << tosimplify.numerator;
        }
        
        else
        {
            if (abs(tosimplify.numerator) > abs(tosimplify.denominator))
            {
                int integer = 0, newNumer = 0;
                int sign = 1;
                
                integer = abs(tosimplify.numerator)/abs(tosimplify.denominator);
                newNumer = abs(tosimplify.numerator)%abs(tosimplify.denominator);
                
                if (tosimplify.numerator*tosimplify.denominator < 0)
                {
                    sign = -1;
                }
                out << integer*sign << "+" << newNumer << "/" << tosimplify.denominator;
            }
            
            else
            out << tosimplify.numerator << "/" << tosimplify.denominator;
        }
        
        return out;
    }
    
    
    
    
    
    
    istream& operator>>(istream& in, Fraction& right)
    {

        char sign1 = '+', sign2 = '/';
        
        
        in >> right.numerator >> sign2;
        
        
    
        if (sign2 == '+')
        {
            in.putback(sign2);

            
            int integer;
            
            integer = right.numerator;
            
            

            in >> sign1 >> right.numerator >> sign2 >> right.denominator;

            if (integer < 0)
            {
                right.numerator = - (abs(integer) * right.denominator + right.numerator);
            }
            else
            {
                right.numerator += integer * right.denominator;
            }
            
    
            return in;
        }

        else if (sign2 != '/' )
        {
            
            in.putback(sign2);
            
            
            
            return in;
        
            
        }
        
        in >> right.denominator;
//
        
        
        
        return in;
    }
    
    
    
    
    /*
     This private function simplifies the calling object's fraction. It will
     determine the sign of the whole fraction and will put the sign in the very
     front.
     
     post: simplifies the fraction and store the fraction as the simplied version
     */
    void Fraction::simplify()
    {
        int sign = 1;
        if (denominator * numerator < 0)
        {
            sign = -1;
        }
        
        Fraction simplifying(abs(numerator), abs(denominator));
        
        for (int i = simplifying.denominator * simplifying.numerator; i > 1; i--)
        {
            if ((simplifying.denominator % i == 0) && (simplifying.numerator % i == 0))
            {
                simplifying.denominator /= i;
                simplifying.numerator /= i;
            }
        }
        
        numerator = simplifying.numerator * sign;
        denominator = simplifying.denominator;
        
        
        
    }
    
    
    
    
    Fraction operator+(const Fraction& left, const Fraction& right)
    {
        Fraction sum;
        
        sum.numerator = left.numerator*right.denominator
                       +left.denominator*right.numerator;
        
        sum.denominator = left.denominator*right.denominator;
        
        sum.simplify();
        return sum;
    }
    
    
    
    
    
    
    Fraction operator-(const Fraction& left, const Fraction& right)
    {
        Fraction difference;
        
        difference.numerator = left.numerator*right.denominator - right.numerator*
        left.denominator;
        
        difference.denominator = left.denominator*right.denominator;
        
        difference.simplify();
        return difference;
    }
    
    
    
    
    
    
    Fraction operator*(const Fraction& left, const Fraction& right)
    {
        Fraction product;
        
        product.numerator = left.numerator*right.numerator;
        product.denominator = left.denominator*right.denominator;
        
        product.simplify();
        return product;
    }
    
    
    
    
    
    
    Fraction operator/(const Fraction& left, const Fraction& right)
    {
        Fraction quotient;
        
        quotient.numerator = left.numerator*right.denominator;
        quotient.denominator = left.denominator*right.numerator;
        
        quotient.simplify();
        return quotient;
    }
    
    
    
    
    
    bool operator<(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue < rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    bool operator<=(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue <= rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator>(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue > rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator>=(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue >= rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator==(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue == rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator!=(const Fraction& left, const Fraction& right)
    {
        double leftvalue, rightvalue;
        
        leftvalue = double(left.numerator) / double(left.denominator);
        rightvalue = double(right.numerator) / double(right.denominator);
        
        if (leftvalue != rightvalue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    Fraction Fraction::operator+=(const Fraction& right)
    {
        *this = *this + right;
        
        return *this;
    }
    
    
    
    
    
    
    Fraction Fraction::operator-=(const Fraction& right)
    {
        *this = *this - right;
        
        return *this;
    }
    
    
    
    
    
    
    Fraction Fraction::operator*=(const Fraction& right)
    {
        *this = *this * right;
        
        return *this;
    }
    
    
    
    
    
    
    Fraction Fraction::operator/=(const Fraction& right)
    {
        *this = *this / right;
        
        return *this;
    }
    
    
    
    
    
    
    Fraction Fraction::operator++()
    {
        
        numerator += denominator;
        
        return *this;
    }
    
    
    
    
    
    Fraction Fraction::operator++(int)
    {
        Fraction saving = *this;
        
        numerator += denominator;
        
        return saving;
    }
    
    
    
    
    
    
    Fraction Fraction::operator--()
    {
        
        numerator -= denominator;
        
        return *this;
    }
    
    
    
    
    
    Fraction Fraction::operator--(int)
    {
        Fraction saving = *this;
        
        numerator -= denominator;
        
        return saving;
    }
}








