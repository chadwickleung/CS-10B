//
//  Cyberdemon.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Cyberdemon.hpp"
#include "Creature.hpp"
#include "Demon.hpp"

#include <iostream>

using namespace std;

namespace cs_Creature
{
    Cyberdemon::Cyberdemon()
    : Demon()
    {
        
    }
    
    
    
    
    
    
    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints)
    {
        
    }
    
    
    
    
    
    
    string Cyberdemon::getSpecies() const
    {
        return "Cyberdemon";
    }
    
    
    
    
    
    
//    int Cyberdemon::getDamage() const
//    {
////        cout << "The Cyberdemon ";
//        
//        int damage;
//        
//        damage = Demon::getDamage();
//        
//        return damage;
//        
//    }
    
    
    
}
