//
//  a3_1.cpp
//  a3_1

//  This program would play a number guessing game with a human user.
//  It would intake a number and allow the user to determine if the number is
//  higher or lower than the user's number, and its next guess would be the
//  half-point of the new boundaries provided by the user.

//  Created by Chadwick Leung on 2/1/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

// function prototypes
void playOneGame();
void getUserResponseToGuess(int, char&);
int getMidpoint(int, int);

int main()
{
    // declare variable
    char response;
    
    // prompt the user
    cout << "Ready to play (y/n)? ";
    cin >> response;
    
    while (response == 'y')
    {
        playOneGame();
        
        // prompt the user if he want s to play again
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
    
    return 0;
}

void playOneGame()
// pre: response is 'y'
//post: find out what the human user's number is
{
    //declare variables
    int compguess;
    char resultcheck;
    int low = 1, high = 100;
    
    do
    {
        compguess = getMidpoint(low, high);
        
        cout << "My guess is " << compguess << ". ";
        
        getUserResponseToGuess(compguess,resultcheck);
        
        if (resultcheck == 'l')
        {
            high = compguess;
        }
        else if (resultcheck == 'h')
        {
            low = compguess;
        }

    }
    while (resultcheck != 'c');
 
}

void getUserResponseToGuess(int guess, char & result)
// pre: a guess is produced
//post: allow user to determine whether his number is higher or lower than the
//      computer's guess, or the guess is correct
{
    cout << "Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin  >> result;
}

int getMidpoint(int low, int high)
// pre: the user has determined whether his number is higher or lower than the guess
//post: return the value of the midpoint
{
    int midpoint;
    
    midpoint = (low + high)/2;
    
    return midpoint;
}

//Ready to play (y/n)? Program ended with exit code: y
//My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 87. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 78. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
//Great! Do you want to play again (y/n)? y
//My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 62. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 56. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 59. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 57. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 58. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
//Great! Do you want to play again (y/n)? n

