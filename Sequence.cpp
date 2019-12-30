//
// Created by Aishwarya Supekar on 11/25/19.
//

#include "Sequence.h"
#include "Inverter.h"
using namespace std;

bool Inverter::isSeeded = false;

bool Sequence::validateWord(string word) {
    return word.length() >= 3;
}

void Sequence::setWord(string word) {
    if(validateWord(word)){
        this->word = word;
    }
}

string Sequence::getWord() {
    return this->word;
}

Sequence::Sequence() {
    this->word = "";
    this->state = ACTIVE;
}

Sequence::Sequence(string word, State state) {
    if(validateWord(word)){
        this->word = word;
        this->state = state;
    }
}

State Sequence::getState() {
    return state;
}

string Inverter::invert() {
    char temp;
    srand(time(NULL));
    string word = seq->getWord();
    int size = word.length();

    if(checkValidity(index, word)) {
        char *array = new char[size];
        for (int i = 0; i < size; i++) {
            array[i] = word[i];
        }
        temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;

        word = convertToString(array, size);
    }
    return word;
}

bool Inverter::checkValidity(int index, string word) {
    int size = word.length();
    if(index >= size-1 || index < 0){
        return false;
    }
    return true;
}

Inverter::Inverter(Sequence* seq) {
    this->seq = seq;
    this->index = getRandomNumber(seq->getWord().length()-1);
}

Inverter::Inverter() {
    this->index = 0;
}

string Inverter::convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int Inverter :: getRandomNumber(int maxRange){
    if(!Inverter::isSeeded){
        srand(time(NULL));
        Inverter::isSeeded = true;
    }

    int randNum = rand() % maxRange;
    return randNum;
}