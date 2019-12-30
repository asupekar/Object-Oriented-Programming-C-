//
// Created by Aishwarya Supekar on 11/26/19.
//

#ifndef ICE9_MAIN_H
#define ICE9_MAIN_H
#include "List.h"
#include <iostream>
using namespace std;
#include "List.h"

template <class T>
void print(List<T> list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list.get(i) << " ";
    cout << endl;
}

int main()
{
    const int SIZE = 10;

    // create list of integers
    List<double> intList(SIZE);

    // populate lists
    for (int i = 0; i < SIZE; i++)
        intList.add(i * 2);

    //print lists
    cout << "integer list values: " << endl;
    print(intList);

    // populate again
    for (int i = 0; i < SIZE; i++)
        intList[i]++;

    //print lists
    cout << "integer list values: " << endl;
    print(intList);

    return 0;
};


#endif //ICE9_MAIN_H
