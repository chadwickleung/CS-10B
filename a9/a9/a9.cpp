//
//  a9.cpp
//  a9
//
//  Created by Chadwick Leung on 4/3/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include "fraction.h"

using namespace std;

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




//The result starts off at 0/1
//The product of 9/8 and 2/3 is 3/4
//The quotient of 9/8 and 2/3 is 27/16
//The sum of 9/8 and 2/3 is 43/24
//The difference of 9/8 and 2/3 is 11/24
//The two Fractions are not equal.
//The product of 3/2 and 2/3 is 1/1
