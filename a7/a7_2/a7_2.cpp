/*
 
 Chadwick Leung
 CS 10B
 3/18/19
 Dave Harden
 Assignment 7_2
 
 This program would read in a sequence of characters enteredby the user and
 terminated by a period. It allows the user to enter multiple lines of input
 by pressing the enter key at the end of each line. The program would print out a
 frequency table, sorted in decreasing order by the number of occurences, listing
 each letter that occured along with the number of times it occured. All non-
 alphabetic characters are ignored. Any characters entered after the period are
 left in the input stream unprocessed.
 
 This program is using struct array to make the data more organized. The sorting
 and display are extracted from assignment 7_1, and the sorting and displaying
 were using ASCII code after using isalpha to test whether the char is an alphabet.
 
 */

#include <iostream>
#include <iomanip>

using namespace std;

struct data{
            int numOftimes;
            char theAlphabet;
           };






int main()
{
    char ch;
    data frequency[26];
    
    
    for (int count=0; count<26; count++)
    {
        frequency[count].numOftimes=0;
        frequency[count].theAlphabet='a'+count;
    }
    
    cout << "Please enter a sequence of characters terminated with a period ('.'): ";
    cout << endl;
    cin >> ch;
    
    while (ch != '.')
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            frequency[ch-97].numOftimes++;
        }

        cin >> ch;
    }

    for (int count=0; count<26; count++)
    {
        for (int seccount=1; seccount<(26-count); seccount++)
        {
            if (frequency[count+seccount].numOftimes > frequency[count].numOftimes)
            {
                data swapptr;
                swapptr = frequency[count];
                
                frequency[count] = frequency[count+seccount];
                frequency[count+seccount] = swapptr;
                
            }
        }
    }
    
    cout << "Frequency table:" <<endl;
    cout << "Letter: " << setw(6) << "Number of Occurences: " <<endl;
    
    for (int count=0; count<26; count++)
    {
        if (frequency[count].numOftimes != 0)
        {
            cout << frequency[count].theAlphabet << ": " << setw(6);
            cout << frequency[count].numOftimes <<endl;
        }
        
    }
 
    return 0;
}


//Please enter a sequence of characters terminated with a period ('.'):
//Program ended with exit code: I am very handsome.xyzz
//Frequency table:
//Letter: Number of Occurences:
//a:      2
//e:      2
//m:      2
//h:      1
//i:      1
//d:      1
//n:      1
//o:      1
//r:      1
//s:      1
//v:      1
//y:      1
