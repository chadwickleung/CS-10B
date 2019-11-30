//
//  Human.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Human.hpp"
#include "Creature.hpp"

#include <iostream>

using namespace std;

namespace cs_Creature
{
    Human::Human()
    : Creature(10, 10)
    {
        
    }
    
    
    
    
    
    
    Human::Human(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints)
    {
        
    }
    
    
    
    
    
    
    string Human::getSpecies() const
    {
        return "Human";
    }
    
    
    
    
    
    
//    int Human::getDamage() const
//    {
//        int damage;
//        
//        damage = Creature::getDamage();
//        
////        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
//        
//        return damage;
//    }
    
    
    
}
