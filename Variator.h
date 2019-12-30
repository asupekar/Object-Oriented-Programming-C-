/**
 * Author: Aishwarya Supekar
 * File name: Variator.h
 * Version: 1.0
 * References: none
 * Description: A class that emits a variant of the encapsulated word, either concatenating or
 *              truncating an internal subsequence. If active, the object will arbitrarily concatenate or
 *              truncate an internal subsequence; otherwise, it will emit the word itself.
 * Dependencies: A Variator is-a Sequence.
 * (List any additional dependencies. Are all behaviors and
 * attributes inherited? Is anything suppressed?)
 * State: Any state changes observed in the Variator.
 * (should align with the pre/postconditions)
 * Assumptions:
 * - Assumption 1 for DerivedClass
 * - Assumption 2 for DerivedClass
*/

#ifndef ASUPEKAR_HW7_VARIATOR_H
#define ASUPEKAR_HW7_VARIATOR_H

#include <iostream>

using namespace std;

class Variator : public Sequence{

public:

    // This is the emit override function from sequence class
    // Precondition: Status of word should be active, word length must be greater than or equal to 3
    // Postconditon: State is guaranteed to be set to ACTIVE
    //               after calling this function
    string emit();

    // This is the isActive function to check the state of the word
    // Precondition: Word length must be greater than or equal to 3
    // Postconditon: State is maintained after calling this function
    bool isActive();

    // This is the parametrised constructor ehich sets the word and state of the word
    // Precondition: Status of word should be active, word length must be greater than or equal to 3
    // Postconditon: State is guaranteed to be set to ACTIVE
    //               after calling this function
    Variator(string, State);

    int getRandomNumber(int); // For generating a random number

private:

    static bool isSeeded; // To generate new random number evrytime a rand() function is called.

    // This function depending on the starting and ending index either concatenates the string or truncates the string
    // Precondition: random number generated should be in between the word size
    // Postconditon: string generated is a subsequence of the string
    //
    string variateString(int, int, bool);
};


#endif //ASUPEKAR_HW7_VARIATOR_H
