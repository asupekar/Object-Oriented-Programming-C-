//
// Created by Aishwarya Supekar on 11/20/19.
//

#include "CaesarCipherList.h"

CaesarCipherList :: CaesarCipherList(int capacity){
    this->capacity = capacity;
    numElements = 0;
    list = new CaesarCipher[this->capacity];
}

CaesarCipherList::~CaesarCipherList() {
    delete [] list;
}

CaesarCipherList::CaesarCipherList(const CaesarCipherList &obj) {
    capacity = obj.capacity;
    numElements = obj.numElements;
    list = new CaesarCipher[capacity];
    for(int i = 0; i < numElements; i++){
        list[i] = obj.list[i];
    }
}

CaesarCipherList &CaesarCipherList::operator=(const CaesarCipherList &obj) {
    if (this != &obj) {
        delete[] list;
        capacity = obj.capacity;
        numElements = obj.numElements;
        list = new CaesarCipher[capacity];
        for (int i = 0; i < numElements; i++) {
            list[i] = obj.list[i];
        }
    }
    return *this;
}

void CaesarCipherList::addElement(CaesarCipher el) {
    if(numElements >= capacity){
        resize();
    }
    list[numElements] = el;
    numElements++;
}

CaesarCipher CaesarCipherList::getElement(int element) const {
    for(int i = 0; i < capacity; i++){
        if(i == element){
            return list[i];
        }
    }
    return CaesarCipher();
}

int CaesarCipherList::size() const {
    return numElements;
}

void CaesarCipherList::resize() {
    capacity = capacity*2;
    CaesarCipher *temp = new CaesarCipher[capacity];
    for(int i = 0; i < numElements; i++){
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;

}