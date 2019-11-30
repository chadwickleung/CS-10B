//
//  a12_1.cpp
//  a12_1
//
//  Created by Chadwick Leung on 4/23/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//
/*
 Chadwick Leung
 CS 10B
 5/15/19
 Dave Harden
 Assignment 15_1
 
 This program would read in any number of MyStrings from the user and determines
 if each MyString is a palindrome (A palindrome is a string that reads the same
 forward and backward) by using recursive function.
 
 The user will terminate each MyString by pressing the return (or enter) button.
 The user will indicate that there are no more MyStrings by entering "quit".
 */

#include "mystring.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <string>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
using namespace cs_mystring;


bool isAPalindrome(MyString& array, int, int);


int main()
{
//    BasicTest();
//    RelationTest();
//    ConcatTest();
//    CopyTest();
    
    MyString s;
    
    cout << "Enter a string: ";
    
    s.read(cin, '\n');
    
    while (s!= "quit")
    {
        int length = s.length();
        
        for (int i = 0; i < length; i++)
        {
            s[i] = toupper(s[i]);
        }
        
        if (isAPalindrome(s, 0, length-1))
        {
            cout << s << " is a palindrome.";
            cout << endl;
        }
        else
        {
            cout << s << " is not a palindrome.";
            cout << endl;
        }
        
        cout << "Enter a string: ";
        
        s.read(cin, '\n');
    }
    
    
    
    


    return 0;
}







/*
 This is a recursive function that takes a single MyString argument and two arguments
 that are bounds on array indices. This function will examine the part of the
 argument between the two bounds and return true if this part of the argument is
 a palindrome.
 
 pre: the MyString is input as array, the first indices is input as start, and the
 last indices is input as end
 post: return true if the array is palindrome, return false if otherwise
 */
bool isAPalindrome(MyString& array, int start, int end)
{
    if (ispunct(array[start]))
    {
        start += 1;
    }
    
    if (isspace(array[start]))
    {
        start += 1;
    }
    
    if (ispunct(array[end]))
    {
        end -= 1;
    }
    
    if (isspace(array[end]))
    {
        end -= 1;
    }
    
    if (array[start] == array[end])
    {
        if (start+1 >= end-1)
        {
            return true;
        }
        
        
        else
        {
            return isAPalindrome(array, start+1, end-1);
            
        }
        
    }
    
    else
    {
        return false;
    }

}








//Enter a string: Able was I, ere I saw Elba
//ABLE WAS I, ERE I SAW ELBA is a palindrome.
//Enter a string: peanut butter
//PEANUT BUTTER is not a palindrome.
//Enter a string: quit
