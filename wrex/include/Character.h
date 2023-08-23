/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <name@uleth.ca>,
 *          Rocky Au                <name@uleth.ca>,
 *          Juhyoung Park           <name@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


class Character {
 public:
    Character();

    virtual ~Character() {}

    std::string getName();

    double getHealth();

    double getAttack();

    double getDefense();

    unsigned int getPosition();

 private:
    std::string name;
    double weight;
    double health;
    double damage;
    double defense;
    unsigned int position;
};


#endif  // CHARACTER_H
