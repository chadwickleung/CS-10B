//
//  Cyberdemon.hpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#ifndef Cyberdemon_hpp
#define Cyberdemon_hpp

#include "Demon.hpp"
#include "Creature.hpp"
#include <iostream>

namespace cs_Creature
{
    class Cyberdemon: public Demon
    {
    public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHitpoints);
        
//        int getDamage() const;
        string getSpecies() const;
    };
    
    
    
    
}


#endif /* Cyberdemon_hpp */
