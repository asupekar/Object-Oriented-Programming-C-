//// This program demonstrates the CaesarCipher class'
//// Big 4 operations and overloaded operators
#include "CaesarCipher.h"
#include "CaesarCipherList.h"
#include <string>
#include <iostream>
using namespace std;

void print(CaesarCipher);

int main() {

    for(int i = 1; i < 3; i++) {
        cout << "\n***** RUN " << i <<" : *****";
        cout << "\ntest constructor : cc" << endl;
        CaesarCipher cc;
        print(cc);

        cout << "\ntest constructor : cc2" << endl;
        CaesarCipher cc2;
        print(cc2);

        cout << "\n*** testing copy constructor and overloaded assignment ***" << endl;
        cout << "\ntest copy constructor : cc3(cc2)" << endl;
        CaesarCipher cc3(cc2);
        print(cc3);

        cout << "\ntest overloaded assignment operator : cc2 = cc" << endl;
        cc2 = cc;
        print(cc2);

        cout << "\n*** printing cc, cc2, and cc3 ***" << endl;

        cout << "\ntest constructor : cc" << endl;
        print(cc);

        cout << "\ntest constructor : cc2" << endl;
        print(cc2);

        cout << "\ntest constructor : cc3" << endl;
        print(cc3);

        cout << "\n*** testing comparators ***" << endl;

        cout << "\ntest comparators" << endl;

        cout << boolalpha<< "\ncc == c3 is " << cc.operator==(cc3) << endl;

        cout << "\ncc < c3 is " << cc.operator<(cc3) << endl;

        cout << "\ncc > c3 is " << cc.operator>(cc3) << endl;

        cout << "\n*** testing add ***" << endl;

        cout << "\ntest add : cc2 = cc + cc3" << endl;
        cc2 = cc + cc3;
        print(cc2);

        cout << "\n*** testing increment ***" << endl;

        cout << "\ntest increment (postfix) : cc4 = cc++" << endl;
        CaesarCipher cc4 = cc++;
        print(cc);

        cout << "\nresult of cc4 after postfix :" << endl;
        print(cc4);

        cout << "\ntest increment (prefix) : cc4 = ++cc" << endl;
        cc4 = ++cc;
        print(cc);

        cout << "\nresult of cc4 after prefix :" << endl;
        print(cc4);

        cout << "\ntest increment (postfix) : cc4 = cc2++" << endl;
        cc4 = cc2++;
        print(cc2);

        cout << "\nresult of cc4 after postfix :" << endl;
        print(cc4);

        cout << "\ntest increment (prefix) : cc4 = ++cc2" << endl;
        cc4 = ++cc2;
        print(cc2);

        cout << "\nresult of cc4 after prefix :" << endl;
        print(cc4);

        cout << "\ntest increment (postfix) : cc4 = cc3++" << endl;
        cc4 = cc3++;
        print(cc3);

        cout << "\nresult of cc4 after postfix :" << endl;
        print(cc4);

        cout << "\ntest increment (prefix) : cc4 = ++cc3" << endl;
        cc4 = ++cc3;
        print(cc3);

        cout << "\nresult of cc4 after prefix :" << endl;
        print(cc4);


        cout << "\n*** testing list ***" << endl;

        cout << "\ntest list : add cc, cc2, cc3" << endl;

        cout << "\ntest print list[0] :"<<endl;

        CaesarCipherList list(3);
        CaesarCipherList cp = CaesarCipherList (list);
        cp.addElement(cc);
        cp.addElement(cc2);
        cp.addElement(cc3);
        cout<<"\n";

        for(int i = 0;i < cp.size(); i++){
            print(cp.getElement(i));
            cout<<"\n";
        }

    }
    return 0;
}

void print(CaesarCipher text) {

    string encryptedWord = text.encrypt("Hello, world!");
    cout << "Encrypted: " << encryptedWord << endl;
    string decryptedWord = text.decrypt(encryptedWord);
    cout << "Decrypted: " << decryptedWord << endl;
}