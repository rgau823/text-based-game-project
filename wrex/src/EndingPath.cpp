/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 4, 2021
 */

#include "EndingPath.h"

int EndingPath::maxPotion = 7;
int EndingPath::redpotionCounter = 0;
int EndingPath::bossSaved = 0;

void EndingPath::drinkPotion() {
    redpotionCounter++;
}

bool EndingPath::canDrinkPotion() {
    return redpotionCounter < maxPotion;
}

void EndingPath::savedBoss() {
    bossSaved++;
}

int EndingPath::getSaved() {
    return bossSaved;
}
