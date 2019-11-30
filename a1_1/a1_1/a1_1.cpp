//
//  a1_1.cpp
//  a1_1
//
//  Created by Chadwick Leung on 1/16/19.
//
//  This program would determine whether the product of the day and month
//  equals the year.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    //declare variables
    int month, day, year, product;
    char ch1, ch2;
    
    //prompt for the user
    cout << "Enter a date in the format month/day/2-digit-year: ";
    //allow user to enter the data
    cin  >> month >> ch1 >> day >> ch2 >> year;
 
    product = month*day;
    
    //if statement to determine the magicness
    if (product == year)
    {
        cout << "This is a magic date!";
    }
    else
    {
        cout << "The date is not magic...";
    }
    
    return 0;
}

//Enter a date in the format month/day/2-digit-year: 06/10/60
//This is a magic date!

//Enter a date in the format month/day/2-digit-year: Program ended with exit code: 03/3/78
//The date is not magic...
