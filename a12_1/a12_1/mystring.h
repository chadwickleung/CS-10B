//
//  mystring.hpp
//  a12_1
//
//  Created by Chadwick Leung on 4/23/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Chadwick Leung
 CS 10B
 4/29/19
 Dave Harden
 Assignment 13
 
 This is the file mystring.h
 
 The MyString class will handle constructing strings, reading/printing, and accessing
 characters. In addition, the MyString object will have the ability to make a full deep
 copy of itself when copied.  This object is designed to make working with sequences of
 characters a little more convenient and less error-prone than handling raw c-strings.
 
 The following functions are available:
 
 MyString();
 post: This is the default constructor that will construct an object with an empty string.
 The string will store a space as the character.
 
 MyString(const char *inDesc);
 This function would assign the object's cstring as the input
 const char *inDesc is used to pass the cstring to the object as dynamic memory.
 pre: a c-string is being input as the const char *inDesc as dynamic array
 post: The object will have a cstring as input by the user, which was stored as dynamic
 array.
 
 MyString(const MyString& right);
 This is the copy constructer that pass the object to the function using pass-by-value.
 This function will change its local copy of the object -- but this change should
 have no effect on the object's value in main because it was passed by value.
 const MyString& right is used to pass the value.
 pre: a value is being assigned to the parameter
 post: change the local copy of the object using pass by value
 
 ~MyString();
 This is a destructor that is called automatically when an object on the stack is
 deallocated.
 post: It will deallocate any memory on the heap that the object is pointing to.
 
 friend std::ostream& operator<<(std::ostream& out, const MyString& printme);
 This is an extraction operator overloading funciton. The ostream& out is used to store
 the object that is being print, and printme is the objec that is input by the user
 pre : an object has been stored in right
 post: insert the object right to the stream out
 
 friend std::istream& operator>>(std::istream& in, MyString& getin);
 This is an insertion operator overloading function. The istream& in is used to store the
 objects from the data file, the getin is the value being extracted from the data file.
 pre : a Fraction object is being input
 post: extract the value of the object to the stream in
 
 int length() const;
 This function would return the number of characters in the string. It uses strlen() to
 measure the length.
 post: return the number of chracters in the string
 
 MyString operator=(const MyString& right);
 This is the assignment operator overoading function. This function would assign
 one object's value to another one using dynamic memory and make a deep copy.
 const MyString& right is the parameter that stores the value of the object using
 dynamic memory.
 pre: a value is store in right
 post: copy the value of the object to the calling object
 
 void read(std::istream& in, char end);
 This function function will allow the client programmer to specify the delimiting
 character (the character at which reading will stop), user would input the
 delimiting character as char end.
 pre: a char end is input by the user in the calling function
 post: would read from the data until it reaches the delimiting character
 specified by the user
 
 char operator[](int index) const;
 This is the square bracket overloading function. This const version const version
 allows read access to the chars. The int index is the element that the user
 is looking for.
 pre : element that the user trying to read
 post: return the char that is in the array that the user asked for
 
 char& operator[](int index);
 This is the square bracket overloading function. This non-const version that
 returns the client a reference to the char so they can change the value.
 pre: user had chosen the element that he wants to know
 post: return a reference to the char that the user asked for so he can
 change the value
 
 friend bool operator<(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is smaller than right,
 return false if otherwise
 
 
 friend bool operator<=(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is smaller than or equal to right,
 return false if otherwise
 
 friend bool operator>(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is greater than right,
 return false if otherwise
 
 friend bool operator>=(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is greater than or equal to right,
 return false if otherwise
 
 friend bool operator==(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is equal to right,
 return false if otherwise
 
 friend bool operator!=(const MyString& left, const MyString& right);
 This is a relational operator overloading function. It can compare MyString objects
 to other MyStrings as well as MyStrings to c-strings. The ordering will be based on
 ASCII values. Since the way ASCII works, it will use the results of calling the
 strcmp() function. MyStrings or c-strings should be able to appear on either side of
 the comparison operator.
 Both const MyString& left and const MyString& right will be used to store the
 object that will be compared.
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return true if value of left is not equal to right,
 return false if otherwise
 
 friend MyString operator+(const MyString& left, const MyString& right);
 This is a concatenation operator overloading function, it is able to handle either
 MyString objects or C-strings on either side of the operator.
 The task is done by using strcpy() to get the left operand into the result MyString,
 and then strcat() to append the right operand.
 Both left and right are used to hold the member function cstring of the objects
 pre: both sides have a value assigned, either a MyString string or a c-string
 post: return a concatenated object, left first, then right
 
 MyString operator+=(const MyString& right);
 This is a combined concatenation and assignment operator overloading function.
 Only MyStrings can be on the left-hand side of a += operation, but either MyStrings
 or C-strings may appear on the right side.
 right is the parameter that holds the object on the right
 pre: the left side has a MhyString object, and the right has a value assigned
 post: return a concatenated object, left first, then right
 
 
 */
#ifndef mystring_hpp
#define mystring_hpp

#include <iostream>

namespace cs_mystring
{
    class MyString
    {
    public:
        MyString();
        MyString(const char *inDesc);
        MyString(const MyString& right);
        ~MyString();
        
        friend std::ostream& operator<<(std::ostream& out, const MyString& printme);
        friend std::istream& operator>>(std::istream& in, MyString& getin);
        
        int length() const;
        
        MyString operator=(const MyString& right);
        
        void read(std::istream& in, char end);
        
        char operator[](int index) const;
        char& operator[](int index);    
        
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        
        friend MyString operator+(const MyString& left, const MyString& right);
        
        MyString operator+=(const MyString& right);
        
    private:
        char *cstring;
        
    };
}

#endif






//----- Testing basic String creation & printing
//string [0] = Wow
//string [1] = C++ is neat!
//string [2] =
//string [3] = a-z
//
//----- Now reading MyStrings from file
//
//----- first, word by word
//Read string = The
//Read string = first
//Read string = time
//Read string = we
//Read string = will
//Read string = read
//Read string = individual
//Read string = words,
//Read string = next
//Read string = we
//Read string = read
//Read string = whole
//Read string = lines
//
//----- now, line by line
//Read string = The  first  time  we  will
//Read string =     read individual words, next
//Read string = we read whole lines
//
//----- Testing access to characters (using const)
//Whole string is abcdefghijklmnopqsrtuvwxyz
//now char by char: abcdefghijklmnopqsrtuvwxyz
//----- Testing access to characters (using non-const)
//Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ
//
//----- Testing relational operators between MyStrings
//Comparing app to apple
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//Comparing apple to
//Is left < right? false
//Is left <= right? false
//Is left > right? true
//Is left >= right? true
//Does left == right? false
//Does left != right ? true
//Comparing  to Banana
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//Comparing Banana to Banana
//Is left < right? false
//Is left <= right? true
//Is left > right? false
//Is left >= right? true
//Does left == right? false
//Does left != right ? false
//
//----- Testing relations between MyStrings and char *
//Comparing he to hello
//Is left < right? true
//Is left <= right? true
//Is left > right? false
//Is left >= right? false
//Does left == right? false
//Does left != right ? true
//Comparing why to wackity
//Is left < right? false
//Is left <= right? false
//Is left > right? true
//Is left >= right? true
//Does left == right? false
//Does left != right ? true
//
//----- Testing concatentation on MyStrings
//outrageous + milk = outrageousmilk
//milk +  = milk
//+ cow = cow
//cow + bell = cowbell
//
//----- Testing concatentation between MyString and char *
//abcde + XYZ = abcdeXYZ
//XYZ + abcde = XYZabcde
//
//----- Testing shorthand concat/assign on MyStrings
//who += what = whowhatandwhowhat
//what += WHEN = whatWHENandwhatWHEN
//WHEN += Where = WHENWhereandWHENWhere
//Where += why = WherewhyandWherewhy
//
//----- Testing shorthand concat/assign using char *
//I love  += programming = I love programming
//
//----- Testing copy constructor and operator= on MyStrings
//original is cake, copy is fake
//original is cake, copy is fake
//after self assignment, copy is Copy Cat
//Testing pass & return MyStrings by value and ref
//after calling Append, sum is BinkyBoo
//val is winky
//after assign,  val is BinkyBoo
//Program ended with exit code: 0
