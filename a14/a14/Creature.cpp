//
//  a14.cpp
//  a14
//
//  Created by Chadwick Leung on 5/6/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Creature.hpp"

#include <iostream>

using namespace std;






Creature::Creature()
{
    type = 0;
    
    strength = 10;
    
    hitpoints = 10;
}







string Creature::getSpecies() const
{
    switch (type) {
        case 0: return "Human";
        case 1: return "Cyberdemon";
        case 2: return "Balrog";
        case 3: return "Elf";
    }
    return "unknown";
}






int Creature::getDamage() const {
    int damage;
    
    // All Creatures inflict damage which is a random number up to their strength
    damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    
    // Demons can inflict damage of 50 with a 25% chance
//    if (type == 2 || type == 1){
//        if (rand() % 4 == 0) {
//            damage = damage + 50;
//            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
//        }
//    }
    
    // Elves inflict double magical damage with a 50% chance
//    if (type == 3) {
//        if ((rand() % 2) == 0) {
//            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
//            damage *= 2;
//        }
//    }
    
    // Balrogs are so fast they get to attack twice
//    if (type == 2) {
//        int damage2 = (rand() % strength) + 1;
//        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
//        damage += damage2;
//    }
//
    return damage;
}
