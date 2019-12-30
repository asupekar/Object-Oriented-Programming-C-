//
// Created by Aishwarya Supekar on 11/25/19.
//

#include "Extractor.h"

string Extractor::emit() {

    if(isActive()) {

        if(subSequence.empty()){
            return "No subsequence provided";
        }

        int subSequenceSize = subSequence.length();
        int wordSize = getWord().length();

        // Check if subsequence is bigger than word
        if(subSequenceSize > wordSize){
            return "subsequence is not a part of word";
        }

        //Check if both are equal
        if((subSequence.compare(getWord())) == 0){
            return "Both subsequence and word are equal";
        }

        int startingIndex = isSubsquence(subSequence, getWord());

        if(startingIndex == -1){
            return "subsequence is not a part of word";
        }
        // startingIndex is 0 so return the remaining word until the end
        string ret = "";
        if(startingIndex == 0){
            for(int i=subSequenceSize; i<wordSize; i++){
                ret = ret + getWord()[i];
            }
        }else{
            for(int i=0; i<startingIndex; i++){
                ret = ret + getWord()[i];
            }
        }

        return ret;
    }
    return getWord();
}


int Extractor::isSubsquence(string subsequence, string word)
{
    int M = subsequence.length();
    int N = word.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (word[i + j] != subsequence[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

bool Extractor::isActive() {
    if(getState() == ACTIVE) {
        return true;
    }
    return false;
}

Extractor::Extractor(string word, string subSequence, State state) : Sequence(word, state ){
    this -> subSequence = subSequence;


}