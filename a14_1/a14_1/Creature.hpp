//
//  Creature.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <iostream>

using namespace std;

namespace cs_Creature
{
    class Creature
    {
    private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain
        
    public:
        Creature();             // initialize to Human, 10 strength, 10 hitpoints
        Creature(int newStrength, int newHitpoints);
        
        virtual string getSpecies() const;    // returns the type of the species
        virtual int getDamage() const;        // returns the amount of damage this Creature
                                      // inflicts in one round of combat
        int getStrength() const;
        int getHitpoints() const;
        
        void setStrength(int newStrength);
        void setHitpoints(int newHitpoints);
        
        
    };
}

#endif /* Creature_hpp */
