/**
 * @authors Brayden Carlson         <brayden.carlson@uleth.ca>,
 *          Angela De Sousa Costa   <angela.desousacosta@uleth.ca>,
 *          Rocky Au                <rocky.au@uleth.ca>,
 *          Juhyoung Park           <juhyoung.park@uleth.ca>
 *
 * @date October 24, 2021
 */

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>

/**
* A Random Number Generator that uses the Singleton
* pattern to be instantiated once.
*/

class RandomNumberGenerator {
 public:
    /**
    * Get the instance of the RandomNumberGenerator.
    */
    static RandomNumberGenerator& getInstance() {
        static RandomNumberGenerator instance;
        return instance;
    }

    /**
    * Remove copy/move constructor and assignment operator.
    */
    RandomNumberGenerator(RandomNumberGenerator const&) = delete;
    RandomNumberGenerator(RandomNumberGenerator&&) = delete;
    RandomNumberGenerator& operator=(RandomNumberGenerator const&) = delete;
    RandomNumberGenerator& operator=(RandomNumberGenerator&&) = delete;

    /**
    * Get mt19937 engine.
    * @returns the mt19937 engine.
    */
    std::mt19937& getEngine();

 private:
    RandomNumberGenerator();
    ~RandomNumberGenerator() {}
    std::mt19937 mt;
};

/**
* Get a boolean based on a percentage.
* @param[in] p the percentage chance to return true.
* @returns true or false, depending on the percentage.
*/
bool getRandomBoolean(double p);

/**
* Get a random number from a range.
* @param[in] x the minimum range.
* @param[in] y the maximum range.
* @returns a random integer based on the range.
*/
int getRandomNumber(int x, int y);

#endif // RANDOMNUMBERGENERATOR_H
