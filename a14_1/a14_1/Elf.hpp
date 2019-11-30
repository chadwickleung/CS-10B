//
//  Elf.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Elf_hpp
#define Elf_hpp

#include "Creature.hpp"
#include <iostream>

namespace cs_Creature
{
    class Elf: public Creature
    {
    public:
        Elf();
        Elf(int newStrength, int newHitpoints);
        
        int getDamage() const;
        string getSpecies() const;
    };
    
    
    
    
}

#endif /* Human_hpp */



