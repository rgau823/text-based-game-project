/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 3, 2021
 */

#ifndef ART_H
#define ART_H

#include <string>

#include "Display.h"
#include "UserInterface.h"

/**
* A class for the ASCII art in the Game.
*/

class Art {
 public:
    /**
    * Print the introduction.
    */
    void introduction();

    /**
    * Print the logo.
    */
    void logo();

    /**
    * Print the gameover art.
    */
    void gameover();

    /**
    * Print the Stage art.
    * @param[in] i the index of the stage.
    */
    void stage(int i);

    /**
    * Print the Wrex dinosaur.
    */
    void dinosaur();

    /**
    * Print true ending art.
    */
    void trueEnding();

    /**
    * Print neutral ending art.
    */
    void neutralEnding();

    /**
    * Print bad ending art.
    */
    void badEnding();

 private:
    Display display;
    UserInterface ui;
};

#endif // ART_H
