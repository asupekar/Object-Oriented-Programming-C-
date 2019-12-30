/**
 * Author: Aishwarya Supekar
 * File name: Extractor.h
 * Version: 1.0
 * References: none
 * Description: a class that emits a variant (or subsequence) of the encapsulated word, if the provided subsequence is found.
 * Dependencies: A Extractor is-a Sequence.
 * (List any additional dependencies. Are all behaviors and
 * attributes inherited? Is anything suppressed?)
 * State: Any state changes observed in the DerivedClass.
 * (should align with the pre/postconditions)
 * Assumptions:
 * - Words are case sensitive, that means Cat is not same as cat.
 * If no subsequence is provided, we return "No subsequence provided" message from the emit() call.
 * If the subsequence length is greater than word length or if subsequence is not a part of the word then we return
 * "subsequence is not a part of word" message from emit() call.
 * If the subsequence equals encapsulated word, we return "Both subsequence and word are equal" message from the emit()
 * call.
*/
#ifndef ASUPEKAR_HW7_EXTRACTOR_H
#define ASUPEKAR_HW7_EXTRACTOR_H

#include <iostream>
#include "Sequence.h"

using namespace std;

class Extractor : public Sequence {

public:

    // This is the emit override function from sequence class
    // Precondition: Status of word should be active, word length must be greater than or equal to 3
    // Postconditon: State is guaranteed to be set to ACTIVE
    //               after calling this function
    string emit() ;

    // This is the isActive  override function from sequence class
    // Checks the status of the word, if active returns true or false
    // Precondition: Status of the word should be set
    // Postconditon: State is guaranteed to be set
    //               after calling this function
    bool isActive() ;

    // This is the extractor constructor used to initialise word, subsequence and the state of the word.
    // Precondition: Subsequence should be part of the word, word length must be greater than or equal to 3
    // Postconditon: State is guaranteed to be set to ACTIVE, subsequence is set to the passed parameter.
    //               after calling this function
    Extractor(string, string, State);


private:

    string subSequence; //To store the subsequence

    int isSubsquence(string, string); //To validate if the given substring is a part of the word
};


#endif //ASUPEKAR_HW7_EXTRACTOR_H
