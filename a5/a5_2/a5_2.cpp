//
//  a5_2.cpp
//  a5_2
//
//  This program will ask the user to enter the number of scores, create two dynamic
//  arrays sized accordingly, ask the user to enter the indicated numbers of names and
//  scores, and then print the names and scores sorted by score in descending order
//
//  Created by Chadwick Leung on 2/21/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//funtion prototypes
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
    //delcare the size variable
    int size;
    
    //prompt the user
    cout << "How many scores will you enter?: ";
    //let user enter the size
    cin  >> size;
    
    //declare pointer for the names array
    string* namesptr;
    namesptr = new string[size];
    
    //declare pointer for the scores array
    int* scoresptr;
    scoresptr = new int[size];
    
    //execute the functions
    initializeArrays(namesptr, scoresptr, size);
    sortData(namesptr, scoresptr, size);
    
    cout <<endl;
    //display the data
    displayData(namesptr, scoresptr, size);
    
    return 0;
}


void initializeArrays(string names[], int scores[], int size)
// pre: both arrays and size are defined in the main function
//post: will save the two arrays, names and scores
{

    for (int count=0; count<size; count++)
    {
        cout << "Enter the name for score #"<< (count+1) <<": ";
        cin  >> names[count];
        
        cout << "Enter the score for score #"<< (count+1) <<": ";
        cin  >> scores[count];
    }
}


void sortData(string names[], int scores[], int size)
// pre: the arrays and the size are entered by the user
//post: sort the scores in descending order, the names will go with it
{
    int swap;
    string nameswap;
    
    for (int count=0; count<size; count++)
    {
        for (int seccount=1; seccount<(size-count); seccount++)
        {
            if (scores[count+seccount]>scores[count])
            {
                swap = scores[count];
                scores[count] = scores[count+seccount];
                scores[count+seccount] = swap;
                
                nameswap = names[count];
                names[count] = names[count+seccount];
                names[count+seccount] = nameswap;
            }
        }
    }
}


void displayData(const string names[], const int scores[], int size)
// pre: the two arrays are sorted after using the sort function
//post: display the scores in descending order, the name will go with it
{
    cout << "Top Scorers:" <<endl;
    
    for (int count=0; count<size; count++)
    {
        cout << names[count] << ": " << scores[count] <<endl;
    }
}

//How many scores will you enter?: 4
//Enter the name for score #1: Suzy
//Enter the score for score #1: 600
//Enter the name for score #2: Kim
//Enter the score for score #2: 9900
//Enter the name for score #3: Armando
//Enter the score for score #3: 8000
//Enter the name for score #4: Tim
//Enter the score for score #4: 514
//Top Scorers:
//Kim: 9900
//Armando: 8000
//Suzy: 600
//Tim: 514
//Program ended with exit code: 0
