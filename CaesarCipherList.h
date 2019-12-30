// CaesarCipherList.h
// Specification file for the CaesarCipherList class.
#ifndef CAESARCIPHERLIST_H
#define CAESARCIPHERLIST_H
#include "CaesarCipher.h"

class CaesarCipherList {
public:
    // Constructor
    CaesarCipherList(int);

    // Destructor
    ~CaesarCipherList();

    // Copy constructor
    CaesarCipherList(const CaesarCipherList &);

    // Overloaded assignment operator
    CaesarCipherList& operator=(const CaesarCipherList &);

    // Add an element to the list
    void addElement(CaesarCipher);

    // Get element in the list at the provided index
    CaesarCipher getElement(int) const;

    // Get list size;
    int size() const;


private:
    CaesarCipher *list;
    int shift;
    int capacity;	// Capacity of array
    int numElements;	// Number of elements in array
    void resize(); 	// Called to resize array when full
};

#endif