//
//  Human.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include "Creature.hpp"
#include <iostream>

namespace cs_Creature
{
    class Human: public Creature
    {
    public:
        Human();
        Human(int newStrength, int newHitpoints);
        
//        int getDamage() const;
        string getSpecies() const;
    };
    
    
    
    
}

#endif /* Human_hpp */
