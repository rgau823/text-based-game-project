/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <name@uleth.ca>,
 *          Rocky Au                <name@uleth.ca>,
 *          Juhyoung Park           <name@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef EXORCISTSTATE_H
#define EXORCISTSTATE_H

#include <string>


class Enemy;

class ExorcistState {
 public:
    ExorcistState(std::string n) : name(n) {}

    virtual ~ExorcistState() {}

    virtual bool attack(Enemy*) = 0;

    virtual bool flee(Enemy*) = 0;

    const std::string name;
};


class SaneState : public ExorcistState {
 public:
    SaneState();

    bool attack(Enemy*);

    bool flee(Enemy*);
};


class InjuredState : public ExorcistState {
 public:
    InjuredState();

    bool attack(Enemy*);

    bool flee(Enemy*);
};


class PossessedState : public ExorcistState {
 public:
    PossessedState();

    bool attack(Enemy*);

    bool flee(Enemy*);
};


#endif  // EXORCISTSTATE_H
