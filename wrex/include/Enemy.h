/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <name@uleth.ca>,
 *          Rocky Au                <name@uleth.ca>,
 *          Juhyoung Park           <name@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "EnemyState.h"

#include <string>


class Enemy : public Character {
 public:
    Enemy();

    virtual ~Enemy();

    bool attack(Exorcist*);

    bool talk(Exorcist*);

    bool gift(Exorcist*);

 private:
    std::string name;
    EnemyState* state;
};


#endif  // ENEMY_H
