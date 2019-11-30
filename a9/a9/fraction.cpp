//
//  fraction.cpp
//  a9
//
//  Created by Chadwick Leung on 4/3/19.
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
#include "fraction.h"

using namespace std;






// post: initialize the fraction as 0/1
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}




// post: initialize the fraction as INnumerator/INdenominator
Fraction::Fraction(int INnumerator, int INdenominator) 
{
    assert(INdenominator != 0);
    
    numerator = INnumerator;
    denominator = INdenominator;

}





// post: print the calling object fraction
void Fraction::print() const
{
    Fraction calling(numerator, denominator);
    
    simplify(calling.numerator, calling.denominator);
    
    cout << calling.numerator << "/" << calling.denominator;
}




/*
 This private function simplifies the calling object's fraction by using
 reference variable
 
 post: simplifies the fraction by referencing the variable
 */

void Fraction::simplify(int &BIGnumerator, int &BIGdenominator) const
{
    for (int i = BIGdenominator * BIGnumerator; i > 1; i--)
    {
        if ((BIGdenominator % i == 0) && (BIGnumerator % i == 0))
        {
            BIGdenominator /= i;
            BIGnumerator /= i;
        }
    }
}





// post: returns the product of the two fractions
Fraction Fraction::multipliedBy(Fraction multiplier) const
{
    Fraction calling(numerator, denominator);
    
    calling.numerator *= multiplier.numerator;
    calling.denominator *= multiplier.denominator;
    
    Fraction result(calling.numerator, calling.denominator);
    
    simplify(result.numerator, result.denominator);
    
    return result;
}







// post: returns the dividend of the two fractions
Fraction Fraction::dividedBy(Fraction divider)
{
    
    Fraction calling(numerator, denominator);
    
    calling.numerator *= divider.denominator;
    calling.denominator *= divider.numerator;
    
    Fraction result(calling.numerator, calling.denominator);
   
    simplify(result.numerator, result.denominator);
    
    return result;
}






// post: returns the sum of the two fractions
Fraction Fraction::addedTo(Fraction adder)
{
    Fraction calling(numerator, denominator);
   
    calling.numerator = calling.numerator*adder.denominator + adder.numerator*
    calling.denominator;
    calling.denominator *= adder.denominator;
    
    
    Fraction result(calling.numerator, calling.denominator);
   
    simplify(result.numerator, result.denominator);
    
    return result;
}






// post: returns the difference betweeen the two fractions
Fraction Fraction::subtract(Fraction subtracter)
{
    Fraction calling(numerator, denominator);
    
    calling.numerator = calling.numerator*subtracter.denominator - subtracter.numerator*
    calling.denominator;
    calling.denominator *= subtracter.denominator;
    
    
    Fraction result(calling.numerator, calling.denominator);
   
    simplify(result.numerator, result.denominator);
    
    return result;
}






// post: returns true if the two fractions are equal
bool Fraction::isEqualTo(Fraction target) const
{
    Fraction calling(numerator, denominator);
    
    //    calling.set(numerator, denominator);
    
    if (calling.numerator*target.denominator == calling.denominator*target.numerator)
        return true;
    else
        return false;
    
}





