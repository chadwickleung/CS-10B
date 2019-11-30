//
//  Balrog.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Balrog_hpp
#define Balrog_hpp

#include "Demon.hpp"
#include "Creature.hpp"
#include <iostream>

namespace cs_Creature
{
    class Balrog: public Demon
    {
    public:
        Balrog();
        Balrog(int newStrength, int newHitpoints);
        
        int getDamage() const;
        string getSpecies() const;
    };
    
}

#endif 
