//
//  a14.hpp
//  a14
//
//  Created by Chadwick Leung on 5/6/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <iostream>
using namespace std;


class Creature
{
private:
    int strength;           // how much damage this Creature inflicts
    int hitpoints;          // how much damage this Creature can sustain
    
public:
    Creature();             // initialize to 10 strength, 10 hitpoints
//    Creature(int newType, int newStrength, int newHitpoints);
    int getDamage() const;         // returns the amount of damage this Creature
    // inflicts in one round of combat
    string getSpecies() const;    // returns the type of the species
    
    // also include appropriate accessors and mutators
};


#endif
