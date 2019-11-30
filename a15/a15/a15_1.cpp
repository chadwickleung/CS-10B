//
//  a15_1.cpp
//  a15
//
//  Created by Chadwick Leung on 5/13/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//
/*
 Chadwick Leung
 CS 10B
 5/15/19
 Dave Harden
 Assignment 15_1
 
 This program would use recursion to reverse the order of those enetities in
 the array whose indices are between the two bounds (including the bounds).
 
 After that, the function created would be used to reverse a string.
 */

#include <iostream>

using namespace std;

void reverseWithinBounds(char [], int , int);
void reverseCstring(char []);

int main()
{
    char a[5] = {'A', 'B', 'C', 'D', 'E'};
    
    for (int count = 0; count < 5; count++)
    {
        cout << a[count];
    }
    
    cout <<endl;
    
    reverseCstring(a);
    
    cout << "After reversing: " <<endl;
    
    for (int count = 0; count < 5; count++)
    {
        cout << a[count];
    }
    
    
    cout <<endl;
    return 0;
}





/*
 This function would reverse the order of those entries in the array whose indices
 are between the two bounds (including the bounds).
 
 pre: array is defined and input as array[], start is input as swap1
 and end is input as swap2
 post:entries in the array would be reversed within swap1 and swap2
 */
void reverseWithinBounds(char array[], int swap1, int swap2)
{
    if (swap1 >= swap2)
    {
        return;
    }
    
    
    char swap = array[swap1];
    array[swap1] = array[swap2];
    array[swap2] = swap;
    
    reverseWithinBounds(array, swap1 + 1, swap2 - 1);
}





/*
 This function would take a single argument that is a C string and will be modified
 using the reverseWithinBounds function to reverse the string
 
 pre: The C-string is input as array[]
 post:The C string would be reversed
 */
void reverseCstring(char array[])
{
    int size = strlen(array);
    
    reverseWithinBounds(array, 0, size-1);
}






//ABCDE
//After reversing:
//EDCBA
