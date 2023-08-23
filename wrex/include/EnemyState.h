/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <name@uleth.ca>,
 *          Rocky Au                <name@uleth.ca>,
 *          Juhyoung Park           <name@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef ENEMYSTATE_H
#define ENEMYSTATE_H

#include <string>


class Exorcist;

class EnemyState {
 public:
    EnemyState(std::string n) : name(n) {}

    virtual ~EnemyState() {}

    virtual bool talk(Exorcist*) = 0;

    virtual bool gift(Exorcist*) = 0;

    virtual bool attack(Exorcist*) = 0;

    const std::string name;
};


class FriendlyState : public EnemyState {
 public:
    FriendlyState();

    bool talk(Exorcist*);

    bool gift(Exorcist*);

    bool attack(Exorcist*);
};


class HostileState : public EnemyState {
 public:
    HostileState();

    bool talk(Exorcist*);

    bool gift(Exorcist*);

    bool attack(Exorcist*);
};


class DeadState : public EnemyState {
 public:
    DeadState();

    bool talk(Exorcist*);

    bool gift(Exorcist*);

    bool attack(Exorcist*);
};


#endif  // ENEMYSTATE_H
