/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

/**
* Exception for an invalid parameter passed into a constructor
* or method.
*/

class invalid_parameter_error : public std::runtime_error {
 public:
    /**
    * @param[in] message an error message.
    */
    explicit invalid_parameter_error(const char* message)
    : std::runtime_error(message) {}
};

#endif // EXCEPTION_H
