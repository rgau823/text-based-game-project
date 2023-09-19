/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date December 3, 2021
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

/**
* A class to read from a file and print the content.
*/

class Display {
 public:
    /**
    * The destructor for Display.
    */
    virtual ~Display() {}

    /**
    * Open a file and print out the contents.
    * @param[in] f the filename of the file.
    */
    void open(const std::string& f);
};

#endif // DISPLAY_H
