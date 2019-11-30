//
//  Balrog.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Balrog.hpp"
#include "Creature.hpp"
#include "Demon.hpp"

#include <iostream>

namespace cs_Creature
{
    Balrog::Balrog()
    : Demon(10, 10)
    {
        
    }
    
    
    
    
    
    
    Balrog::Balrog(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints)
    {
        
    }
    
    
    
    
    
    
    string Balrog::getSpecies() const
    {
        return "Balrog";
    }
    
    
    
    
    
    
    int Balrog::getDamage() const
    {
//        cout << "The Balrog ";
        
        int damage;
        
        damage = Demon::getDamage();
        
        int damage2 = (rand() % Creature::getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        
        return damage;
    }
    
    
    
}
