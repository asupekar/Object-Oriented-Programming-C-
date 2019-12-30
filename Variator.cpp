//
// Created by Aishwarya Supekar on 12/1/19.
//
#include "Sequence.h"
#include "Variator.h"
using namespace std;

bool Variator::isSeeded = false;

string Variator::emit() {
    int randNum;
    int selection = 2;
    string word = getWord();
    int wordLength = word.length();
    if(isActive()){
        randNum = getRandomNumber(selection);

        int startIndex = 0;
        int endIndex = 0;

        while((startIndex >= endIndex )|| (startIndex == 0 && endIndex == wordLength-1)) {
            //concatenate
            startIndex = getRandomNumber(wordLength);
            endIndex = getRandomNumber(wordLength);
        }

        if(randNum == 0){
            //concatenate case
            return variateString(startIndex, endIndex, true);
        } else {
            //truncate case
            return variateString(startIndex, endIndex, false);
        }
    }


    return word;
}

int Variator :: getRandomNumber(int maxRange){
    if(!Variator::isSeeded){
        srand(time(NULL));
        Variator::isSeeded = true;
    }

    int randNum = rand() % maxRange;
    return randNum;
}

bool Variator::isActive() {
    if(getState() == ACTIVE) {
        return true;
    }
    return false;
}


Variator::Variator(string word, State state) : Sequence(word, state){

}

string Variator::variateString(int startIndex, int endIndex, bool operation)
{
    int i;
    long unsigned int j;
    string s = "";
    string variant = "";
    //Concatenate
    if(operation == true)
    {
        for (i = startIndex; i <= endIndex; i++) {
            s = s + getWord()[i];
        }
        variant = getWord() + s;
    }else{
        for (i = 0; i < startIndex; i++) {
            s = s + getWord()[i];
        }
        for(j=endIndex+1; j < getWord().length(); j++){
            s = s + getWord()[j];
        }
        variant = s;
    }


    return variant;
}

