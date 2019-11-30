//
//  Demon.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Demon.hpp"
#include "Creature.hpp"

#include <iostream>

using namespace std;

namespace cs_Creature
{
    Demon::Demon()
    : Creature(10, 10)
    {
        
    }
    
    
    
    
    
    
    Demon::Demon(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints)
    {
        
    }
    
    
    
    
    
    
    string Demon::getSpecies() const
    {
        return "Demon";
    }
    
    
    
    
    
    
    int Demon::getDamage() const
    {
        int totdamage;
        
        totdamage = Creature::getDamage();
        
//        cout << "attacks for " << totdamage << " points!" <<endl;
        
        if (rand() % 4 == 0)
        {
            totdamage = totdamage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        
        return totdamage;
    }
    
    
}
