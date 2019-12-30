//
// Created by Aishwarya Supekar on 11/16/19.
//

#include <iostream>
#include "CaesarCipher.h"
#include "unistd.h"
#include <time.h>

using namespace std;

CaesarCipher newCipher;
bool CaesarCipher::isSeeded = false;

CaesarCipher :: CaesarCipher(){
    shift = getShift() % 10;
    if(shift == 0){
        shift = 1;
    }
}

CaesarCipher :: CaesarCipher(int sift){
    shift = sift;
}

CaesarCipher::CaesarCipher(const CaesarCipher &cipher) {
    shift = cipher.shift;
}

string CaesarCipher::encrypt(string plainText) {
    for(char const &c: plainText){
        int index = (int)c;
        if (!isPositionInRange(index)) {
            throw invalid_argument("String to be encrypted has unrecognized character " +c);
        }
    }
    string result = encryptDecrypt(plainText, true);
    return result;
}

string CaesarCipher::decrypt(string cipherText) {
    string result = encryptDecrypt(cipherText, false);
    return result;
}

CaesarCipher& CaesarCipher::operator=(const CaesarCipher &cipher) {
    shift = cipher.shift;
    return *this;
}

CaesarCipher CaesarCipher::operator+(const CaesarCipher &cipherOther) {
    newCipher.shift = cipherOther.shift + shift;
    return newCipher;
}

bool CaesarCipher::operator == (const CaesarCipher &cipher) {
    if(shift == cipher.shift){
        return true;
    }
    return false;
}

string CaesarCipher::encryptDecrypt(string word, bool flag) {
    string result;
    int deShift = 0;
    for(long unsigned int i =0; i < word.length();i++) {
        if (isupper(word[i])) {
            if(flag == true) {
                result = result + char(int(word[i] + shift - 65) % 26 + 65);
            }
            else{
                deShift = 26 - shift;
                result = result + char(int(word[i] + deShift - 65) % 26 + 65);
            }
        } else if (islower(word[i])){
            if(flag == true) {
                result = result + char(int(word[i] + shift - 97) % 26 + 97);
            }
            else {
                deShift = 26 - shift;
                result = result + char(int(word[i] + deShift - 97) % 26 + 97);
            }
        } else if(isdigit(word[i])){
            if(flag == true) {
                result = result + char(int(word[i] + shift - 48) % 10 + 48);
            }
            else {
                deShift = 10 - shift;
                result = result + char(int(word[i] + deShift - 48) % 10 + 48);
            }
        }
        else {
            if(flag == true) {
                result = result + char(int(word[i] + shift - 32) % 15 + 32);
            }
            else {
                deShift = 15 - shift;
                result = result + char(int(word[i] + deShift - 32) % 15 + 32);
            }
        }
    }
    return result;
}

int CaesarCipher :: getShift() {
    if(!CaesarCipher::isSeeded){
        srand(time(NULL));
        CaesarCipher::isSeeded = true;
    }
    return rand();
}

bool CaesarCipher::operator<(const CaesarCipher &cipher) {
    if(shift < cipher.shift){
        return true;
    }
    return false;
}

bool CaesarCipher::operator>(const CaesarCipher &cipher) {
    if(shift > cipher.shift){
        return true;
    }
    return false;
}

//Pre-increment operator
CaesarCipher& CaesarCipher::operator++() {
    ++shift;
    return *this;
}

//Post-increment operator
CaesarCipher CaesarCipher::operator++(int) {
    const CaesarCipher old(this->shift);
    ++(*this);
    return old;
}

bool CaesarCipher::isPositionInRange(int index) {
    if(index < OFFSET_MIN || index > OFFSET_MAX){
        return false;
    }
    return true;
}