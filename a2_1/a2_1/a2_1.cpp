//
//  a2_1.cpp
//  a2_1
//
//  BlackJack Game
//  Created by Chadwick Leung on 1/22/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    
    char ch2;
    
    do
    {
        srand(time(NULL));
        
        int int1, int2, add, sum=0;
        char ch1;
        
        
        int1 = 1+rand()%(10);
        int2 = 1+rand()%(10);
        
        sum  = int1 + int2;
        
        cout << "First cards: " << int1 << ", " << int2 <<endl;
        cout << "Total: " << sum <<endl;
        
        do
        {
            
            cout << "Do you want another card? (y/n): " ;
            cin  >> ch1;
            
            if (ch1 == 'y')
            {
                add = 1+rand()%(10);
                cout << "Card: " << add <<endl;
                
                sum += add;
                cout << "Total: " << sum <<endl;
                
                if (sum == 21)
                {
                    cout << "Congratulations!"<<endl;
                    ch1 = 'n';
                }
                else if (sum >21)
                {
                    cout << "Bust"<<endl;
                    ch1 = 'n';
                }
            }
        }
        while (ch1 !='n');
        
        cout << "Would you like to play again? (y/n): ";
        cin  >> ch2;
        
    }
    while (ch2 !='n');
    
    return 0;
}


//First cards: 10, 7
//Total: 17
//Do you want another card? (y/n): y
//Card: 1
//Total: 18
//Do you want another card? (y/n): y
//Card: 3
//Total: 21
//Congratulations!
//Would you like to play again? (y/n): y
//First cards: 7, 10
//Total: 17
//Do you want another card? (y/n): y
//Card: 2
//Total: 19
//Do you want another card? (y/n): y
//Card: 5
//Total: 24
//Bust
//Would you like to play again? (y/n):
