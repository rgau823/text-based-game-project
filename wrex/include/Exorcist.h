/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <name@uleth.ca>,
 *          Rocky Au                <name@uleth.ca>,
 *          Juhyoung Park           <name@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef EXORCIST_H
#define EXORCIST_H

#include "Character.h"
#include "ExorcistState.h"

#include <string>
#include <vector>


class Exorcist : public Character {
 public:
    Exorcist();

    virtual ~Exorcist();

    std::string getName();

    bool move();

    double interact();

    bool negotiate();

    bool pickupItem();

    bool equipItem();

    bool useItem();

    bool dropItem();

    bool setHealth(double);

    bool setAttack(double);

    bool setDefense(double);

    bool setPosition(unsigned int);

    void viewBackpack();

    void viewStatus();

    unsigned int getPosition();

    bool attack(Enemy*);

    bool talk(Enemy*);

    bool gift(Enemy*);

    bool flee(Enemy*);

 private:
    std::string name;
    ExorcistState* state;
    std::vector<std::string> backpack;
};


#endif  // EXORCIST_H
