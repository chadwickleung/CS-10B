//
//  a8_1.cpp
//  a8
//
//  Created by Chadwick Leung on 3/26/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

class Fraction{
public:
    void print();
//    void set(int numerator, int deniminator);
    
    Fraction addedTo(Fraction adder);
    Fraction subtract(Fraction subtracter);
    Fraction multipliedBy(Fraction multiplier);
    Fraction dividedBy(Fraction divider);
    Fraction();
    const Fraction(const int, const int);
    
    bool isEqualTo(Fraction target) const;
    
private:
    int numerator;
    int denominator;
};






Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}





Fraction::Fraction(const int INnumerator, const int INdenominator) const
{
    assert(INdenominator != 0);
    
    numerator = INnumerator;
    denominator = INdenominator;
    
    
}






void Fraction::print()
{
    cout << numerator << "/" << denominator;
}






Fraction Fraction::multipliedBy(Fraction multiplier)
{
    const Fraction calling(numerator, denominator);
    
//    calling.set(numerator, denominator);
    
    
    calling.numerator *= multiplier.numerator;
    calling.denominator *= multiplier.denominator;
    
    Fraction result(calling.numerator, calling.denominator);
    
//    result.set(calling.numerator, calling.denominator);
    
    
    return result;
}






Fraction Fraction::dividedBy(Fraction divider)
{
    
    Fraction calling;
    
//    calling.set(numerator, denominator);
    
    calling.numerator *= divider.denominator;
    calling.denominator *= divider.numerator;
    
    Fraction result;
    
//    result.set(calling.numerator, calling.denominator);
    
    return result;
}






Fraction Fraction::addedTo(Fraction adder)
{
    Fraction calling;
    
//    calling.set(numerator, denominator);
    
    calling.numerator = calling.numerator*adder.denominator + adder.numerator*
                        calling.denominator;
    calling.denominator *= adder.denominator;
    
    
    Fraction result;
//
//    result.set(calling.numerator, calling.denominator);
    
    return result;
}






Fraction Fraction::subtract(Fraction subtracter)
{
    Fraction calling;
    
//    calling.set(numerator, denominator);
    
    calling.numerator = calling.numerator*subtracter.denominator - subtracter.numerator*
    calling.denominator;
    calling.denominator *= subtracter.denominator;
    
    
    Fraction result;
    
//    result.set(calling.numerator, calling.denominator);
    
    return result;
}





bool Fraction::isEqualTo(Fraction target) const
{
    Fraction calling;
    
//    calling.set(numerator, denominator);
    
    if (calling.numerator*target.denominator == calling.denominator*target.numerator)
        return true;
    else
        return false;
    
}






int main()
{
    Fraction f1(9,8);
    Fraction f2(2,3);
    Fraction result;
    
    cout << "The result starts off at ";
    result.print();
    cout << endl;
    
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;
    
    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;
    
    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
    
    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
    
    
    return 0;
}






//The product of 9/8 and 2/3 is 18/24
//The quotient of 9/8 and 2/3 is 27/16
//The sum of 9/8 and 2/3 is 43/24
//The difference of 9/8 and 2/3 is 11/24
//The two Fractions are not equal.
