//
//  a4_1.cpp
//  a4_1

//  This program reads five cards from the user, then analyzes the cards
//  and prints out the category of hand that they represent.

//  Created by Chadwick Leung on 2/9/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

//function prototypes
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

//global variable of the number of cards
const int numCards = 5;

int main()
{
 
    //declare variable, an array type
    int cards[numCards];
    
    //prompt the user
    cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n";
    
    for (int count=0; count<numCards; count++)
    {
        cout << "Card " << count+1 << ": ";
        cin  >> cards[count];
    }
    
    //display the category based on the cards
    if (containsFourOfaKind(cards))
    {
        cout << "contains four of a kind";
    }
    else if (containsFullHouse(cards))
    {
        cout << "contains a full house";
    }
    else if (containsStraight(cards))
    {
        cout << "contains straight";
    }
    else if (containsThreeOfaKind(cards))
    {
        cout << "contains three of a kind";
    }
    else if (containsTwoPair(cards))
    {
        cout << "contains two pairs";
    }
    else if (containsPair(cards))
    {
        cout << "contains a pair";
    }
    
    //high card has no related function
    else
    {
        cout << "contains high card";
    }
    
    return 0;
}


bool containsPair(const int hand[])
// pre: user has input the five cards
//post: return true if there is a pair
{

    int compare[8]={0,0,0,0,0,0,0,0};
 
    int numOfpotentialCards=8;
    
    int numOfPairs=0;
    
    for (int count=0; count<numCards; count++)
    {
        for (int comparecount=0; comparecount<numOfpotentialCards; comparecount++)
        {
            if (hand[count]==(comparecount+2))
            {
                compare[comparecount]++;
            }
        }
    }
    
    for (int ccount=0; ccount<numOfpotentialCards; ccount++)
    {
        if (compare[ccount] ==2)
        {
            numOfPairs++;
        }
    }
    
    
    if (numOfPairs==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool containsTwoPair(const int hand[])
// pre: user has input the five cards
//post: return true if there is two pairs
{
    int compare[8]={0,0,0,0,0,0,0,0};
    
    int numOfpotentialCards=8;
    
    int numOfPairs=0;
    
    for (int count=0; count<numCards; count++)
    {
        for (int comparecount=0; comparecount<numOfpotentialCards; comparecount++)
        {
            if (hand[count]==(comparecount+2))
            {
                compare[comparecount]++;
            }
        }
    }
    
    for (int ccount=0; ccount<numOfpotentialCards; ccount++)
    {
        if (compare[ccount] ==2)
        {
            numOfPairs++;
        }
    }
    
    
    if (numOfPairs==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool containsThreeOfaKind(const int hand[])
// pre: user has input the five cards
//post: return true if there is three of a kind
{
    int compare[8]={0,0,0,0,0,0,0,0};
    
    int numOfpotentialCards=8;
    
    int numOfPairs=0;
    
    for (int count=0; count<numCards; count++)
    {
        for (int comparecount=0; comparecount<numOfpotentialCards; comparecount++)
        {
            if (hand[count]==(comparecount+2))
            {
                compare[comparecount]++;
            }
        }
    }
    
    for (int ccount=0; ccount<numOfpotentialCards; ccount++)
    {
        if (compare[ccount] ==3)
        {
            numOfPairs++;
        }
    }
    
    
    if (numOfPairs==1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


bool containsFullHouse(const int hand[])
// pre: user has input the five cards
//post: return true if there is a full house, which means there is a pair
//      and a three of a kind
{
    if (containsThreeOfaKind(hand) && containsPair(hand))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool containsFourOfaKind(const int hand[])
// pre: user has input the five cards
//post: return true if there is four of a kind
{
    int compare[8]={0,0,0,0,0,0,0,0};
    
    int numOfpotentialCards=8;
    
    int numOfPairs=0;
    
    for (int count=0; count<numCards; count++)
    {
        for (int comparecount=0; comparecount<numOfpotentialCards; comparecount++)
        {
            if (hand[count]==(comparecount+2))
            {
                compare[comparecount]++;
            }
        }
    }
    
    for (int ccount=0; ccount<numOfpotentialCards; ccount++)
    {
        if (compare[ccount] ==4)
        {
            numOfPairs++;
        }
    }
    
    
    if (numOfPairs==1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


bool containsStraight(const int hand[])
// pre: user has input the five cards
//post: return true if the cards are straight
{
    int min=9;
    int steps=1;
    
    //determining the smallest card
    for (int count=0; count<numCards; count++)
    {
        if (hand[count]<min)
        {
            min = hand[count];
        }
    }

    for (int ccount=0; ccount<numCards; ccount++)
    {
        for (ccount=0; ccount<numCards; ccount++)
        {
            if (hand[ccount]==(min+1))
            {
                steps++;
                min = hand[ccount];
            }
        }
    }
    
    if (steps==5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 3
//Card 2: 4
//Card 3: 2
//Card 4: 5
//Card 5: 6
//contains straight
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 2
//Card 2: 2
//Card 3: 2
//Card 4: 2
//Card 5: 5
//contains four of a kind
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 2
//Card 2: 3
//Card 3: 2
//Card 4: 3
//Card 5: 4
//contains two pairs
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 2
//Card 2: 3
//Card 3: 4
//Card 4: 7
//Card 5: 8
//contains high card
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 3
//Card 2: 3
//Card 3: 5
//Card 4: 6
//Card 5: 7
//contains a pair
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 3
//Card 2: 3
//Card 3: 3
//Card 4: 5
//Card 5: 5
//contains a full house
//Program ended with exit code: 0

//Enter five numeric cards, no face cards. Use 2 - 9.
//Card 1: 7
//Card 2: 7
//Card 3: 7
//Card 4: 8
//Card 5: 9
//contains three of a kind
//Program ended with exit code: 0
