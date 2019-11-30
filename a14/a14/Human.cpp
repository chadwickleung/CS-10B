//
//  Human.cpp
//  a14
//
//  Created by Chadwick Leung on 5/6/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

#include "Human.hpp"
#include "Creature.hpp"

#include <iostream>

using namespace std;






string Human::getSpecies() const
{
    return "Human";
}






Human::Human()
{
    strength = 10;
    
    hitpoints = 10;
}






