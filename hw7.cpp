/**
 * Author: Aishwarya Supekar
 * File name: hw7.cpp
 * Version: 1.0
 * References: none
 * Description: A class that tests all the functionality
 * Dependencies: A main class that requires all header files for accessing their functionality
 * Emit behaviour of Sequence is tested with invert method of Inverter
 * (List any additional dependencies. Are all behaviors and
 * attributes inherited? Is anything suppressed?)
 * State: Any state changes observed in the DerivedClass.
 * (should align with the pre/postconditions)
 * Assumptions:
 * - Assumption 1 for DerivedClass
 * - Assumption 2 for DerivedClass
*/

#include <iostream>

#include "Sequence.h"
#include "Inverter.h"
#include "Repeater.h"
#include "Extractor.h"
#include "Variator.h"
#include <fstream>
using namespace std;

static bool isSeeded = false;

// This is the readFile function which reads random lines from the words.dat file
// Precondition: The file should not be empty
// Postconditon: The words array will be filled with random line word.
string readFile(){
    int randNum;
    int numOfLines = 0;
    string line;
    ifstream inFile;
    inFile.open("words.dat");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    } else {
        while(getline(inFile, line)){
            numOfLines++;
        }

        if(!isSeeded){
            srand(time(NULL));
            isSeeded = true;
        }
        randNum = rand() % numOfLines + 1;
        int currentLine = 0;
        ifstream readFile;
        readFile.open("words.dat");
        while(getline(readFile, line)){
            if(currentLine == randNum)
            {
                break;
            }
            currentLine++;
        }
        inFile.close();
        readFile.close();
    }
    return line;

}

// This is the mian function
// Precondition: State should be ready to set
// Postconditon: State is either set to Active or Inactive.
int main() {

    cout << "Welcome to the Sequence tester! " << endl;
    const int SIZE = 9;
    Sequence *seqArr[SIZE];
    string line;
    const int length = 3;
    string word[3];

    for (int i = 0; i < length; i++) {
        line = readFile();
        word[i] = line;
    }

    int count = 3;
    for (int i = 0; i < 3; i++) {

        int j = 0;

        if(i > 0){
            j = i*3;
        }

        line = word[i];

        Repeater* rep = new Repeater(line, ACTIVE);
        if(rep->getWord().empty()){
            cout<<"Word "<<line<< " length is not greater than 3."<<endl;
            count = count - 1;
            continue;
        }
        seqArr[j] = rep;

        string subSequence = line.substr(0, line.length() / 2);
        Extractor* ex = new Extractor(line, subSequence, ACTIVE);
        seqArr[j+1] = ex;

        Variator* var = new Variator(line, ACTIVE);
        seqArr[j+2] = var;
    }

    //Print Seq array
    for(int i =0;i<SIZE;i++){
        cout << seqArr[i]->getWord() << endl;
    }

    int i = 0;
    for(int j=0;j<3;j++){
        cout << "\n----------" << endl;
        cout << "Testing word " << j + 1 << ":" << endl;
        line = word[j];
        if(j>0){
            i = j*3;
        }
        int limit = 0;
        while(i<SIZE && limit < 3) {
            if(limit == 3){
                break;
            }
            cout << "\nemit: " << seqArr[i]->emit() << endl;
            Inverter inv(seqArr[i]);
            cout << "invert: " << inv.invert() << endl;
            limit++;
            i++;
        }
        string response;
        string answer = "y";
        while (answer == "y" || answer == "Y") {
            cout << "\nWhat is your guess? ";

            cin >> response;

            if (response.compare(line) == 0) {
                cout << "That's correct!" << endl;
                break;
            } else {
                cout << "That is not correct.\nGuess again (y/n)? ";
                cin >> answer;
            }
        }
    }

    string input, response;
    cout << "Testing word 4 (additional functionality):\n" << endl;
    do {
        response = "n";
        line = readFile();
        Repeater rep(line, ACTIVE);
        if(rep.getWord().empty()){
            cout<<"Word "<<line<< " length is not greater than 3."<<endl;
            response = 'y';
            continue;
        }
        Inverter inv(&rep);
        cout << "invert: " << inv.invert() << endl;
        do {
            if(!isSeeded){
                srand(time(NULL));
                isSeeded = true;
            }

            int endIndex = rand() % (line.length() - 2) + 1;
            string subSequence = line.substr(0,  endIndex);
            cout << "\nprovide a subsequence: " << subSequence << endl;
            Extractor ex(line, subSequence, ACTIVE);
            cout << "emit: " << ex.emit() << endl;
            cout << "\nProvide another subsequence (y/n)? ";
            cin >> input;
        } while (input == "y" || input == "Y");
        do {
            cout << "\nWhat is your guess? ";
            cin >> response;
            if (response == line) {
                cout << "That's correct!" << endl;
            } else {
                cout << "That is not correct.\n"
                        "Guess again (y/n)? ";
                cin >> response;
            }
        } while (response == "y" || response == "Y");

        cout << "Would you like to test another word (y/n)? ";
        cin >> response;
    }while (response == "y" || response == "Y");
    cout<<"\n----------"<<endl;
    cout<<"Thanks for using the Sequence tester!"<<endl;
    return 0;
}