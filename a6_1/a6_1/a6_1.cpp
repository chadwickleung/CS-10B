//
//  a6_1.cpp
//  a6_1
//  c-string and pointer practice
//  Created by Chadwick Leung on 3/3/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

//function prototypes
int lastIndexOf(const char* inString, char target); //done
void reverse(char* inString); //done
int replace(char* inString, char target, char replacementChar); //done
bool isPalindrome(const char* inString); //done
void toupper(char* inString);
int numLetters(const char* inString); //done

int main()
{
    //define variables
    char str1[] = "Hello World";
    char str2[] = "C++ is fun!";
    char str3[] = "abba";
    char str4[] = "ababa";
    
    //for this example, I chose the target to be 'l' and the string to be
    //'Hello World'
    char target1 = 'l';
    cout << "The last index of '"<< target1 <<"' in '"<< str1<<"' is " << lastIndexOf(&str1[0], target1)<<endl;
    //this is for when there is no target char in the string, then the index will stay as -1
    cout << "Since there is no '"<< target1<< "' in '"<< str2<< "', the index becomes "<<lastIndexOf(str2, target1)<<endl;
    
    cout <<endl;
    
    //for this example, I chose the string to be 'Hello World' and reverse it
    cout <<"The reverse of '"<< str1 << "' is ";
    reverse(str1);
    
    cout <<endl<<endl;
    
    //for this example, I chose the target to be 'l' and the replacement to be 'z',
    //and the string to be 'Hello World'
    char target3 = 'l';
    char replace1 = 'z';
    int numoftimes = replace(str1, target3, replace1);
    cout << "For the c-string 'Hello World', we have to replace 'l' with 'z' "<< numoftimes<< " times to make it 'Hezzo Worzd'"<<endl;
    //this is for when there is no target char in the string
    cout << "Since there is no 'l' in 'C++ is fun!', the number of replacement is "<<replace(str2, target3, replace1)<<endl;
    
    cout <<endl;
    
    
    //for this example, I chose the string to be 'abba' (even number)
    cout <<str3;
    if (isPalindrome(str3))
    {
        cout << " is palindrome"<<endl;
        
    }
    else
    {
        cout << " is not palindrome"<<endl;
    }
    //odd number 'ababa'
    cout <<str4;
    if (isPalindrome(str4))
    {
        cout << " is palindrome"<<endl;
    }
    else
    {
        cout << " is not palindrome"<<endl;
    }
    //show an example that is not palindrome 'C++ is fun!'
    cout << str2;
    if (isPalindrome(str2))
    {
        cout << " is palindrome"<<endl;
    }
    else
    {
        cout << " is not palindrome"<<endl;
    }
    
    cout <<endl;

    //for this example, I chose the string to be 'abba'
    cout << "The string '"<< str3 << "' becomes ";
    toupper(str3);
    
    cout <<endl<<endl;
    //for this example, I chose the string to be 'abba'
    cout << "There are " << numLetters(&str3[0]) << " letters in 'abba'.\n";
    
    return 0;
}


int lastIndexOf(const char* inString, char target)
// pre: c-string and target are assigned
//post: the index of the last target occurs
{
    int i=0;
    int index=-1;
    
    while (inString[i] != '\0')
    {
        if (inString[i] == target)
        {
            index = i;
        }
        i++;
    }
    
    return index;

}


void reverse(char* inString)
// pre: c-string is assigned
//post: the reverse of the c-string is produced
{
    int size;
    size = strlen(inString);
    int i=0;

    //since the last character is right before \0
    while(inString[i] != '\0')
    {
        cout << inString[size-1-i];
        i++;
    }
}

int replace(char* inString, char target, char replacementChar)
// pre: c-string, target, and the replacement char are assigned
//post: present the number of replacements made
{
    int i=0;
    int numofreplacement=0;
    
    while (inString[i] != '\0')
    {
        if (inString[i] == target)
        {
            inString[i] = replacementChar;
            numofreplacement++;
        }
        i++;
    }
 
    return numofreplacement;
}

bool isPalindrome(const char* inString)
// pre: c-string assigned
//post: return a bool value determined by whether the c-string is palindrome
{
    int size;
    size = strlen(inString);
    int i=0;
    bool decide;
    
    while(inString[i] != '\0')
    {
        if (inString[i] == inString[size-1-i])
        {
            decide = true;
        }
        else
        {
            return false;
        }
        i++;
    }
    
    return decide;


}

void toupper(char* inString)
// pre: c-string assigned
//post: convert all lower-case to upper-case
{
    int i=0;
    
    while (inString[i] != '\0')
    {
        cout << char(toupper(inString[i]));
        i++;
    }
}

int numLetters(const char* inString)
// pre: c-string assigned
//post: return the number of letters in the c-string
{
    int size;
    
    size = strlen(inString);
    
    return size;
}

//The last index of 'l' in 'Hello World' is 9
//Since there is no 'l' in 'C++ is fun!', the index becomes -1
//
//The reverse of 'Hello World' is dlroW olleH
//
//For the c-string 'Hello World', we have to replace 'l' with 'z' 3 times to make it 'Hezzo Worzd'
//Since there is no 'l' in 'C++ is fun!', the number of replacement is 0
//
//abba is palindrome
//ababa is palindrome
//C++ is fun! is not palindrome
//
//The string 'abba' becomes ABBA
//
//There are 4 letters in 'abba'.
//Program ended with exit code: 0
