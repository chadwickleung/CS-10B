//
//  Human.hpp
//  a14
//
//  Created by Chadwick Leung on 5/6/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include "Creature.hpp"
#include <iostream>

using namespace std;

class Human: public Creature
{
public:
    Human();             // initialize to Human, 10 strength, 10 hitpoints
    Human(int newStrength, int newHitpoints);
    int getDamage() const;         // returns the amount of damage this Creature
    // inflicts in one round of combat
    string getSpecies() const;    // returns the type of the species
    
};

#endif
