//
// Created by Aishwarya Supekar on 11/16/19.
//
// CaesarCipher.h
// Specification file for the CaesarCipher class.
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>
using namespace std;

class CaesarCipher {
public:
    CaesarCipher();

    CaesarCipher (int);

    CaesarCipher(const CaesarCipher &);

    string encrypt(string);

    string decrypt(string);

    CaesarCipher& operator=(const CaesarCipher &);

    CaesarCipher operator+(const CaesarCipher &);

    bool operator==(const CaesarCipher &);

    bool operator<(const CaesarCipher &);

    bool operator>(const CaesarCipher &);

    CaesarCipher& operator++();

    CaesarCipher operator++(int);

private:
    int shift;
    const int OFFSET_MIN = 32;
    const int OFFSET_MAX = 126;
    int getShift();
    string encryptDecrypt(string, bool);
    bool isPositionInRange(int);
    static bool isSeeded;
};

#endif




