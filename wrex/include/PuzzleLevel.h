/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef PUZZLELEVEL_H
#define PUZZLELEVEL_H

#include <string>

#include "Display.h"
#include "Level.h"

/**
* A PuzzleLevel is a unique level where the
* Exorcist must solve a puzzle in order to
* proceed. In doing so, a reward could be
* given or the ability to unlock the next
* Stage.
*/

class PuzzleLevel : public Level {
 public:
    /**
    * The default constructor for PuzzleLevel.
    */
    PuzzleLevel();

    /**
    * The destructor for PuzzleLevel.
    */
    virtual ~PuzzleLevel() {}

    /**
    * Set the status of the PuzzleLevel.
    * @param[in] s a boolean indicating if the Level was solved.
    */
    void setSolved(bool s);

    /**
    * The actual puzzle that will be done
    */
    virtual void puzzle() = 0;

    /**
    * Get the status of the PuzzleLevel.
    * @returns a boolean indicating if the Level was solved.
    */
    virtual bool isCleared();

    /**
    * When the player interacts with a PuzzleLevel, puzzle method is called.
    */
    virtual void interact();

 protected:
    Display display;

 private:
    std::string path;
    std::string question;
    unsigned int answer;
    bool solved = false;
};

#endif // PUZZLELEVEL_H
