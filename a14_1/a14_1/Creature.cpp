//
//  Creature.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Creature.hpp"
#include <iostream>

using namespace std;

namespace cs_Creature
{
    Creature::Creature()
    {
        strength = 10;
        
        hitpoints = 10;
    }
    
    
    
    
    
    
    Creature::Creature(int newStrength, int newHitpoints)
    {
        strength = newStrength;
        
        hitpoints = newHitpoints;
    }
    
    
    
    
    
    int Creature::getStrength() const
    {
        return strength;
    }
    
    
    
    
    
    
    int Creature::getHitpoints() const
    {
        return hitpoints;
    }
    
    
    
    
    
    
    int Creature::getDamage() const
    {
        int damage;
        
        // All Creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        
        return damage;
    }
    
    
    
    
    
    
    string Creature::getSpecies() const
    {
        return "Creature";
    }
    
    
    
    
    
    
    void Creature::setStrength(int newStrength)
    {
        strength = newStrength;
    }
    
    
    
    
    
    
    void Creature::setHitpoints(int newHitpoints)
    {
        hitpoints = newHitpoints;
    }
}
