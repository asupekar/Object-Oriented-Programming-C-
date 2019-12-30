/**
 * Author: Aishwarya Supekar
 * File name: Sequence.h
 * Version: 1.0
 * References: none
 * Description: A class that emits a variant of the encapsulated word, either concatenating or
 *              truncating an internal subsequence. If active, the object will arbitrarily concatenate or
 *              truncate an internal subsequence; otherwise, it will emit the word itself.
 * Dependencies: A Sequence is a base class.
 * (List any additional dependencies. Are all behaviors and
 * attributes inherited? Is anything suppressed?)
 * State: Any state changes observed in the Variator.
 * (should align with the pre/postconditions)
 * Assumptions:
 * If a word is less than 3 characters long, we do not initialize the word in the Sequence constructor.
 *  States is defined as an enum with ACTIVE and INACTIVE members. Initially all the objects created are treated as
 *  ACTIVE
*/

#ifndef ASUPEKAR_HW7_SEQUENCE_H
#define ASUPEKAR_HW7_SEQUENCE_H

#include <iostream>

using namespace std;

//Enum for declaring the state of the word.
enum State {ACTIVE, INACTIVE};

class Sequence {

public:
    // This is the default constructor.
    // Precondition: State is set to ACTIVE & word is set to null
    // Postconditon: State is guaranteed to be set to ACTIVE
    //               after calling this function
    Sequence();

    // This is the parametrised constructor.
    // Precondition: State is set to state provided in parameter & word is set to string provided in the parameter
    // Postconditon: State is guaranteed to have some state and word is set to a value greater than or equal to 3.
    //               after calling this function
    Sequence(string, State);

    // This is the validateWord function
    // Precondition: word length should not be zero
    // Postconditon: word length is greater than three
    //               after calling this function
    bool validateWord(string string1);


    // This is the setWord function
    // Precondition: word length should be greater than or equal to zero
    // Postconditon: word is set to the parameter passed
    //               after calling this function
    void setWord(string);


    // This is the getWord function
    // Precondition: no parameter should be passed
    // Postconditon: State is guaranteed to be set to ACTIVE
    //               after calling this function
    string getWord();

    // This is the getState function
    // Precondition: State should not be changed
    // Postconditon: State is returned after calling this function
    State getState();


    // This is the emit which emits the word.
    // Precondition:
    // Postconditon:
    // As this method is not implemented in Sequence, no pre post conditions are applicable.
    virtual string emit() = 0;


private:

    string word;// the word to be set for encapsulation

    State state; // State of the word
};


#endif //ASUPEKAR_HW7_SEQUENCE_H
