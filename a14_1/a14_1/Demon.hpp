//
//  Demon.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Demon_hpp
#define Demon_hpp

#include "Creature.hpp"
#include <iostream>

namespace cs_Creature
{
    class Demon: public Creature
    {
    public:
        Demon();
        Demon(int newStrength, int newHitpoints);
        
        int getDamage() const;
        string getSpecies() const;
    };
    
    
    
    
}

#endif /* Demon_hpp */
