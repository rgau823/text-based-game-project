/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 05, 2021
 */

#ifndef SHADOWBOSS_H
#define SHADOWBOSS_H

#include "Boss.h"

/**
 * ShadowBoss is one of the bosses in the game.
 * It has specific values and responses in the game
 */

class ShadowBoss : public Boss {
 public:
    /**
     * The default constructor for the shadow boss 
     */
    ShadowBoss();

    virtual void update();

    virtual bool takeItem(Item* i);

    virtual void buff(Character* c);
};

#endif // SHADOWBOSS_H
