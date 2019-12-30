/**
 * Author: Aishwarya Supekar 
 * File name: Inverter.h
 * Version: 1.0
 * References: none
 * Description: a class that based on index i and, according to state, supports the inversion of 
 *              two elements (or characters) of a given sequence at indices i and i+1. 
 * Dependencies: A Inverter has a sequence 
 * (List any additional dependencies. Are all behaviors and
 * attributes inherited? Is anything suppressed?)
 * State: Any state changes observed in the DerivedClass.
 * (should align with the pre/postconditions)
*/

#ifndef ASUPEKAR_HW7_INVERTER_H
#define ASUPEKAR_HW7_INVERTER_H

#include <iostream>
#include "Sequence.h"

using namespace std;


class Inverter {
    
    
public:
    // This is the invert function that based on index i and, according to state, supports the inversion of two elements 
    // Precondition: Status of word should be active, word length must be greater than or equal to 3
    // Postconditon: word length is not chnaged and state of the word is maintained after calling this method.
    string invert();

    // This is the constructor of the inverter
    // Index is set to zero
    // Precondition: no pre conditions
    // Postconditon: no post conditions
    Inverter();

    // This is the constructor of the inverter with sequence object as parameter
    // Index is set to random number
    // Precondition: word should be of 3 or more letters
    // Postconditon: State of the word is active and word is not changed 
    Inverter(Sequence*);

private:
    int index;// Index used for inversion of the letters
    
    static bool isSeeded; // To generate new random number everytime rand() is called
    
    bool checkValidity(int, string); // To check the validity of word size
    
    string convertToString(char *a, int size); // To convert char array to string
    
    Sequence* seq; // Sequence object
    
    int getRandomNumber(int); // For generating a random number
};


#endif //ASUPEKAR_HW7_INVERTER_H
