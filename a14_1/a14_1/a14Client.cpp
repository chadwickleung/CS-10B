//
//  a14Client.cpp
//  a14_1
//
//  Created by Chadwick Leung on 5/7/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Creature.hpp"
#include "Human.hpp"
#include "Elf.hpp"
#include "Cyberdemon.hpp"
#include "Demon.hpp"
#include "Balrog.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

void battleArena( cs_Creature::Creature &Creature1, cs_Creature::Creature& Creature2);

using namespace std;
using namespace cs_Creature;

int main()
{
//    srand(static_cast<unsigned>(time(nullptr)));
//
//    Human h1;
//    Elf e1;
//    Cyberdemon c1;
//    Balrog b1;
//
//    Human h(20, 30);
//    Elf e(40, 50);
//    Cyberdemon c(60, 70);
//    Balrog b(80, 90);
//
//
//    cout << "default Human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
//    cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
//    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
//    cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
//    cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
//    cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
//    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
//    cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
//    cout << endl << endl;
//
//
//    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
//    for (int i = 0; i < 10; i++){
//        int damage = h.getDamage();
//        cout << " Total damage = " << damage << endl;
//        cout << endl;
//    }
//    cout << endl;
//
//
//
//    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
//    for (int i = 0; i < 10; i++){
//        int damage = e.getDamage();
//        cout << " Total damage = " << damage << endl;
//        cout << endl;
//    }
//    cout << endl;
//
//
//
//    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
//    for (int i = 0; i < 10; i++){
//        int damage = c.getDamage();
//        cout << " Total damage = " << damage << endl;
//        cout << endl;
//    }
//    cout << endl;
//
//
//
//    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
//    for (int i = 0; i < 10; i++){
//        int damage = b.getDamage();
//        cout << " Total damage = " << damage << endl;
//        cout << endl;
//    }
//    cout << endl;
    
    
    srand(static_cast<unsigned>(time(0)));
    
    Elf e(50,50);
    Balrog b(50,50);
    
    battleArena(e, b);    
    
    
    
    return 0;
}





void battleArena(cs_Creature::Creature &Creature1, cs_Creature::Creature& Creature2)
{
    int damage1, damage2;
    
    int life1, life2;
   
    do
    {
        damage1 = Creature1.getDamage();
        
        cout << "Total damage = " << damage1 <<endl;
        
        
        damage2 = Creature2.getDamage();
        
        cout << "Total damage = " << damage2 <<endl;
        
        
        life1 = Creature1.getHitpoints();
        
        life1 -= damage2;
        
        Creature1.setHitpoints(life1);
        
        life2 = Creature2.getHitpoints();
        
        life2 -= damage1;
        
        Creature2.setHitpoints(life2);
        
        cout << "After this round, " <<endl;
        cout << Creature1.getSpecies() << " has remaining hitpoints of " << life1 <<endl;
        cout << Creature2.getSpecies() << " has remaining hitpoints of " << life2 <<endl;
    }
    while (life1 > 0 && life2 > 0);
    
    if (life1 < 0 && life2 < 0)
    {
        cout << "Tie" <<endl;
    }
    
    else if (life1 == 0 && life2 == 0)
    {
        cout << "Tie" <<endl;
    }
    else if (life1 > life2)
    {
        cout << Creature1.getSpecies() << " wins " <<endl;
    }
    
    
    else
    {
        cout << Creature2.getSpecies() << " wins " <<endl;
    }
}






//The Elf attacks for 40 points!
//Total damage = 40
//The Balrog attacks for 18 points!
//Balrog speed attack inflicts 15 additional damage points!
//Total damage = 33
//After this round,
//Elf has remaining hitpoints of 17
//Balrog has remaining hitpoints of 10
//The Elf attacks for 21 points!
//Total damage = 21
//The Balrog attacks for 29 points!
//Balrog speed attack inflicts 3 additional damage points!
//Total damage = 32
//After this round,
//Elf has remaining hitpoints of -15
//Balrog has remaining hitpoints of -11
//Tie
