//
//  Elf.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Elf.hpp"
#include "Creature.hpp"

#include <iostream>

using namespace std;

namespace cs_Creature
{
    Elf::Elf()
    : Creature(10, 10)
    {
        
    }
    
    
    
    
    
    
    Elf::Elf(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints)
    {
        
    }
    
    
    
    
    
    
    string Elf::getSpecies() const
    {
        return "Elf";
    }
    
    
    
    
    
    
    int Elf::getDamage() const
    {
        int totdamage;
        
        totdamage = Creature::getDamage();
        
//        cout << getSpecies() << " attacks for " << totdamage << " points!" << endl;
        
        if ((rand() % 2) == 0)
        {
            cout << "Magical attack inflicts " << totdamage << " additional damage points!" << endl;
            totdamage *= 2;
        }
        
        return totdamage;
    }
    
    
    
}
