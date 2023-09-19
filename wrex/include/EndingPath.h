/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 4, 2021
 */

#ifndef ENDINGPATH_H
#define ENDINGPATH_H

/**
* Keep track of the bosses saved throughout the Game.
*/

class EndingPath {
 public:
    static int maxPotion;
    static int redpotionCounter;
    static int bossSaved;
    static void drinkPotion();
    static bool canDrinkPotion();
    static void savedBoss();
    static int getSaved();
};

#endif // ENDINGPATH_H
