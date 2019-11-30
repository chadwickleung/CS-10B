//
//  mystring.cpp
//  a12_1
//
//  Created by Chadwick Leung on 4/23/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Class Invariant:
 The MyString class has only one char data member and is stored as
 dynamic memory. This object is designed to make working with sequences of
 characters a little more convenient and less error-prone than handling raw
 c-strings, (although it will be implemented as a c-string behind the scenes).
 The MyString class will handle constructing strings, reading/printing, and
 accessing characters. In addition, the MyString object will have the ability
 to make a full deep-copy of itself when copied.
 */






#include "mystring.h"
#include <iostream>
#include <string.h>


using namespace std;

namespace cs_mystring
{
    MyString::MyString(const char *inDesc)
    {
        cstring = new char[strlen(inDesc)+1];
        
        strcpy(cstring, inDesc);
    }
    
    
    
    
    
    
    MyString::MyString ()
    {
        cstring = new char[1];
        strcpy(cstring, " ");
    }
    
    
    
    
    
    
    int MyString::length() const
    {
        int length;
        
        length = strlen(cstring);
        
        return length;
    }
    
    
    
    
    
    
    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right)
        {
            delete [] cstring;
            cstring = new char[strlen(right.cstring) + 1];
            
            strcpy(cstring, right.cstring);
        }
        
        return *this;
    }
    
    
    
    
    
    
    MyString::MyString(const MyString& right)
    {
        cstring =  new char[strlen(right.cstring) + 1];
        
        strcpy(cstring, right.cstring);
    }
    
    
    
    
    
    
    MyString::~MyString()
    {
        delete [] cstring;
    }
    
    
    
    
    
    
    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }
    
    
    
    
    
    
    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }
    
    
    
    
    
    
    ostream& operator<<(ostream& out, const MyString& printme)
    {
        out << printme.cstring;
        
        return out;
    }
    
    
    
    
    
    
    istream& operator>>(istream& in, MyString& getin)
    {

        in >> getin.cstring;

       





        return in;
    }
    
    
    
    
    bool operator<(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value < 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    bool operator>(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value > 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator<=(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value < 0 || value == 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator>=(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value > 0 || value == 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator==(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value = 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    bool operator!=(const MyString& left, const MyString& right)
    {
        int value;
        
        value = strcmp(left.cstring, right.cstring);
        
        if (value != 0)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    
    
    
    
    
    MyString operator+(const MyString& left, const MyString& right)
    {
        MyString s;
        
        int length;
        
        length = strlen(left.cstring) + strlen(right.cstring);
        
        s.cstring = new char[length+1];
        
        strcpy(s.cstring, left.cstring);
        
        strcat(s.cstring, right.cstring);

        return s;
    }
    
    
    
    
    
    
    MyString MyString::operator+=(const MyString& right)
    {
        *this = *this + right;
        
        return *this;
    }
    
    
    
    
    
    void MyString::read(istream& in, char end)
    {
        char *somestring;
        
        somestring = new char[128];
        
        in.getline(somestring, 127, end);
        
        strcpy(cstring, somestring);
    }
}
