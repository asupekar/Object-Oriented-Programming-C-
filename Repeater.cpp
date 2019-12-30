//
// Created by Aishwarya Supekar on 11/25/19.
//

#include "Sequence.h"
#include "Repeater.h"
using namespace std;

string Repeater::emit()  {
    string word = getWord();
    if(isActive()) {
        int size = word.length() + 1;

        char *letters = new char[size];
        for (long unsigned int i = 0; i < word.length(); i++) {
            letters[i] = word[i];
        }

        srand(time(NULL));
        int randomIndex = rand() % (size + 1);

        char charAtRandomIndex = word[randomIndex];

        letters[size-1] = charAtRandomIndex;

        string variant = convertToString(letters, size);

        return variant;
    }
    return word;
}

string Repeater::convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

bool Repeater::isActive() {
    if(getState() == ACTIVE) {
        return true;
    }
    return false;
}


Repeater::Repeater(string word, State state) : Sequence(word, state) {
}
