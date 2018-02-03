////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       tester.cpp
//  Date:           08/27/2017
//  Description:    Main tester for assignment 1.
//
////////////////////////////////////////////////////////////////////////////////
//
//  Honor Pledge:
//
//  I pledge that I have neither given nor received any help on this assignment.
//
//  ibsardar
//
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2017 Copyright Holder All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
#include <string>
#include "Array.h"

int test_array_default_max_size = 10;
std::string test_helper_bool(int);                  // COMPLETE
bool test_array_ctor_any(Array,int,int,char *);     // COMPLETE
bool test_array_ctor_void();                        // COMPLETE
bool test_array_ctor_length();                      // COMPLETE
bool test_array_ctor_length_fill();                 // COMPLETE
bool test_array_ctor_copy();                        // COMPLETE
bool test_array_dtor();                             // COMPLETE
bool test_array_operator_brackets();                // COMPLETE
bool test_array_operator_equals();                  // COMPLETE
bool test_array_operator_not_equals();              // COMPLETE
bool test_array_get();                              // COMPLETE
bool test_array_set();                              // COMPLETE
bool test_array_resize();                           // COMPLETE
bool test_array_find();                             // COMPLETE
bool test_array_find_start();                       // COMPLETE
bool test_array_fill();                             // COMPLETE
bool test_array_size();                             // COMPLETE
bool test_array_max_size();                         // COMPLETE

std::string test_helper_bool(int i) {
    if (i) {
        return "Passed";
    } else {
        return "Failed";
    }
}

bool test_array_ctor_any(Array a, int sz, int mx, char * data) {

    bool a1 = (a.size() == sz);

    bool a2 = (a.max_size() == mx);

    bool a3 = true;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != data[i]) {
            a3 = false;
            break;
        }
    }

    return (a1 && a2 && a3);
}

bool test_array_ctor_void() {

    Array a = Array();

    bool a1 = (a.size() == test_array_default_max_size);

    bool a2 = (a.max_size() == test_array_default_max_size);

    bool a3 = true;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != ' ') {
            a3 = false;
            break;
        }
    }

    return (a1 && a2 && a3);
}

bool test_array_ctor_length() {

    Array a = Array(0);
    Array b = Array(1);
    Array c = Array(test_array_default_max_size+1);

    bool a1 = (a.size() == test_array_default_max_size);
    bool b1 = (b.size() == 1);
    bool c1 = (c.size() == (test_array_default_max_size+1));

    bool a2 = (a.max_size() == test_array_default_max_size);
    bool b2 = (b.max_size() == test_array_default_max_size);
    bool c2 = (c.max_size() == test_array_default_max_size*2);

    bool a3 = true;
    bool b3 = true;
    bool c3 = true;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != ' ') {
            a3 = false;
            break;
        }
    }
    for (int i=0; i<b.size(); i++) {
        if (b[i] != ' ') {
            b3 = false;
            break;
        }
    }
    for (int i=0; i<c.size(); i++) {
        if (c[i] != ' ') {
            c3 = false;
            break;
        }
    }

    return (a1 && a2 && a3 && b1 && b2 && b3 && c1 && c2 && c3);
}

bool test_array_ctor_length_fill() {

    Array a = Array(0,'a');
    Array b = Array(1,'b');
    Array c = Array(test_array_default_max_size+1,'c');

    bool a1 = (a.size() == test_array_default_max_size);
    bool b1 = (b.size() == 1);
    bool c1 = (c.size() == (test_array_default_max_size+1));

    bool a2 = (a.max_size() == test_array_default_max_size);
    bool b2 = (b.max_size() == test_array_default_max_size);
    bool c2 = (c.max_size() == test_array_default_max_size*2);

    bool a3 = true;
    bool b3 = true;
    bool c3 = true;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != 'a') {
            a3 = false;
            break;
        }
    }
    for (int i=0; i<b.size(); i++) {
        if (b[i] != 'b') {
            b3 = false;
            break;
        }
    }
    for (int i=0; i<c.size(); i++) {
        if (c[i] != 'c') {
            c3 = false;
            break;
        }
    }

    return (a1 && a2 && a3 && b1 && b2 && b3 && c1 && c2 && c3);
}

bool test_array_ctor_copy() {

    Array a = Array();
    Array b = Array(0);
    Array c = Array(1);
    Array d = Array(test_array_default_max_size+1);
    Array e = Array(0,'a');
    Array f = Array(1,'b');
    Array g = Array(test_array_default_max_size+1,'c');

    Array h = Array(a);
    bool h1 = (h == a);

    h = Array(b);
    bool h2 = (h == b);

    h = Array(c);
    bool h3 = (h == c);

    h = Array(d);
    bool h4 = (h == d);

    h = Array(e);
    bool h5 = (h == e);

    h = Array(f);
    bool h6 = (h == f);

    h = Array(g);
    bool h7 = (h == g);

    return (h1 && h2 && h3 && h4 && h5 && h6 && h7);
}

bool test_array_dtor() {

    Array * a = new Array(0);
    Array * b = new Array(1);
    Array * c = new Array(test_array_default_max_size+1);

    bool a1 = (a->size() == test_array_default_max_size);
    bool b1 = (b->size() == 1);
    bool c1 = (c->size() == (test_array_default_max_size+1));

    bool a2 = (a->max_size() == test_array_default_max_size);
    bool b2 = (b->max_size() == test_array_default_max_size);
    bool c2 = (c->max_size() == test_array_default_max_size*2);

    bool a3 = true;
    bool b3 = true;
    bool c3 = true;
    for (int i=0; i<a->size(); i++) {
        if ((*a)[i] != ' ') {
            a3 = false;
            break;
        }
    }
    for (int i=0; i<b->size(); i++) {
        if ((*b)[i] != ' ') {
            b3 = false;
            break;
        }
    }
    for (int i=0; i<c->size(); i++) {
        if ((*c)[i] != ' ') {
            c3 = false;
            break;
        }
    }

    delete a;
    delete b;
    delete c;

    return (a1 && a2 && a3 && b1 && b2 && b3 && c1 && c2 && c3);
}

bool test_array_operator_brackets() {

    Array a = Array(2,'k');
    a[1] = 'n';
    a[2] = 'm';
    a[1] = 'l';

    return (a[0] == 'k' && a[1] == 'l');
}

bool test_array_operator_equals() {

    Array a = Array(4,'f');
    a[1] = 'g';
    Array b = Array();
    b.fill('k');
    b[1] = 'g';
    Array c = Array(4,'g');
    c[0] = 'f';
    c[2] = 'f';
    c[3] = 'f';

    return !(a==b) && !(b==a) && !(c==b) && !(b==c) && (a==c) && (c==a);
}

bool test_array_operator_not_equals() {

    Array a = Array(4,'f');
    a[1] = 'g';
    Array b = Array();
    b.fill('k');
    b[1] = 'g';
    Array c = Array(4,'g');
    c[0] = 'f';
    c[2] = 'f';
    c[3] = 'f';

    return (a!=b) && (b!=a) && (c!=b) && (b!=c) && !(a!=c) && !(c!=a);
}

bool test_array_get() {

    Array a = Array(3,'a');
    a[1] = 'b';
    a[2] = 'c';

    return (a.get(0)=='a') && (a.get(1)=='b') && (a.get(2)=='c');
}

bool test_array_set() {

    Array a = Array(3,'a');
    a.set(1,'b');
    a.set(2,'c');

    return (a[0]=='a') && (a[1]=='b') && (a[2]=='c');
}

bool test_array_resize() {

    Array a = Array();
    Array b = Array(3);
    Array c = Array(4,'a');
    Array d = Array(c);
    d = a;

    a.resize(1);
    b.resize(2);
    c.resize(3);
    d.resize(60);
    d.resize(6);
    bool a1 = (a.size()==1) && (b.size()==2) && (c.size()==3) && (d.size()==6) &&
              (a.max_size()==test_array_default_max_size) &&
              (b.max_size()==test_array_default_max_size) &&
              (c.max_size()==test_array_default_max_size) &&
              (d.max_size()==test_array_default_max_size*8);

    a.resize(11);
    b.resize(80);
    b.resize(20);
    c.resize(15);
    d.resize(1200);
    d.resize(1);
    d.resize(121);
    bool a2 = (a.size()==11) && (b.size()==20) && (c.size()==15) && (d.size()==121) &&
              (a.max_size()==test_array_default_max_size*2) &&
              (b.max_size()==test_array_default_max_size*8) &&
              (c.max_size()==test_array_default_max_size*2) &&
              (d.max_size()==test_array_default_max_size*128);

    return a1 && a2;
}

bool test_array_find() {

    Array a = Array(6,'a');
    a[2] = 'b';
    a[5] = 'c';
    a[1] = '1';
    a[3] = '2';

    return (a.find('a')==0) && (a.find('b')==2) && (a.find('c')==5) &&
           (a.find('1')==1) && (a.find('2')==3) && (a.find('d')==-1);
}

bool test_array_find_start() {

    Array a = Array(6,'a');
    a[2] = 'b';
    a[5] = 'c';
    a[1] = '1';
    a[3] = '2';

    return (a.find('a',3)==4) && (a.find('b',3)==-1) && (a.find('c',2)==5) &&
           (a.find('1',1)==1) && (a.find('a',5)==-1) && (a.find('d',6)==-1);
}

bool test_array_fill() {

    Array a = Array(3,'a');
    Array b = Array(12,'b');

    Array c = Array(3);
    c.fill('a');
    bool c1 = (a == c);

    c.fill('b');
    c.resize(12);
    bool c2 = (b != c);

    c.fill('x');
    c.fill('y');
    c.fill('b');
    bool c3 = (b == c);

    return c1 && c2 && c3;
}

bool test_array_size() {

    Array a = Array();
    Array b = Array(1);
    Array c = Array(74);

    return (a.size()==10) && (b.size()==1) && (c.size()==74);
}

bool test_array_max_size() {

    Array a = Array();
    Array b = Array(1);
    Array c = Array(74);

    return (a.max_size()==10) && (b.max_size()==10) && (c.max_size()==80);
}

int main() {

    ////////////////////////////////////////////////////////////////
    std::cout << "tester.cpp is being executed...\n" << std::endl;
    ////////////////////////////////////////////////////////////////

    //***
    // VALGRIND ERROR REPLICATIONS:
    //

    int * arr = new int[3];
    int * arr2 = new int[1];

    // VALGRIND: Invalid read of size 4
    if (arr[3]) {
        // VALGRIND: Invalid write of size 4
        arr[3] = arr2[0];
        // VALGRIND: Invalid write of size 4
        arr2[1] = arr[1];
        // VALGRIND: Invalid write of size 4
        arr2[2] = arr[2];
    }

    delete [] arr;
    delete [] arr2;
    //***/

    /*
    try {

        std::cout << "\n=============\nRunning Tests:\n" << std::endl;
        std::string outs[] = {
            test_helper_bool(test_array_ctor_void()),
            test_helper_bool(test_array_ctor_length()),
            test_helper_bool(test_array_ctor_length_fill()),
            test_helper_bool(test_array_ctor_copy()),
            test_helper_bool(test_array_dtor()),
            test_helper_bool(test_array_operator_brackets()),
            test_helper_bool(test_array_operator_equals()),
            test_helper_bool(test_array_operator_not_equals()),
            test_helper_bool(test_array_get()),
            test_helper_bool(test_array_set()),
            test_helper_bool(test_array_resize()),
            test_helper_bool(test_array_find()),
            test_helper_bool(test_array_find_start()),
            test_helper_bool(test_array_fill()),
            test_helper_bool(test_array_size()),
            test_helper_bool(test_array_max_size())
        };
        std::cout << "\n=============\nTest Results:\n=============\n" << std::endl;
        std::cout << "Void Constructor\t\t: "           << outs[0]  << std::endl;
        std::cout << "Length Constructor\t\t: "         << outs[1]  << std::endl;
        std::cout << "Length Fill Constructor\t\t: "    << outs[2]  << std::endl;
        std::cout << "Copy Constructor\t\t: "           << outs[3]  << std::endl;
        std::cout << "Destructor\t\t\t: "               << outs[4]  << std::endl;
        std::cout << "Operator []\t\t\t: "              << outs[5]  << std::endl;
        std::cout << "Operator ==\t\t\t: "              << outs[6]  << std::endl;
        std::cout << "Operator !=\t\t\t: "              << outs[7]  << std::endl;
        std::cout << "Get\t\t\t\t: "                    << outs[8]  << std::endl;
        std::cout << "Set\t\t\t\t: "                    << outs[9]  << std::endl;
        std::cout << "Resize\t\t\t\t: "                 << outs[10] << std::endl;
        std::cout << "Find\t\t\t\t: "                   << outs[11] << std::endl;
        std::cout << "Find Start\t\t\t: "               << outs[12] << std::endl;
        std::cout << "Fill\t\t\t\t: "                   << outs[13] << std::endl;
        std::cout << "Size\t\t\t\t: "                   << outs[14] << std::endl;
        std::cout << "Max Size\t\t\t: "                 << outs[15] << std::endl;
        std::cout << "\nEnd of Test Results\n=============\n" << std::endl;
/****
        Array test_01 = Array();
        //test_01.debug(1);

        Array test_02 = Array(11,'2');
        //test_02.fill('2');
        std::cout << "NEW TEST: Should be \"22222222222\":" << std::endl;
        std::cout << "NEW TEST: "<< test_02[0] << std::endl;
        std::cout << "NEW TEST: "<< test_02[1] << std::endl;
        std::cout << "NEW TEST: "<< test_02[10] << std::endl;
        std::cout << "NEW TEST: "<< test_02[11] << std::endl;
        //test_02.debug(2);

        Array test_03 = Array(3,'3');
        //test_03.debug(3);

        Array test_04 = Array(test_03);
        //test_04.debug(4);

        test_04 = test_02;
        //test_04.debug(4);

        if (test_04 == test_02) {
            std::cout << "Arrays 2 and 4 are equal." << std::endl;
        } else {
            std::cout << "..problem.." << std::endl;
        }
        std::cout << std::endl;

        if (test_04 != test_03) {
            std::cout << "Arrays 3 and 4 are not equal." << std::endl;
        } else {
            std::cout << "..problem.." << std::endl;
        }
        std::cout << std::endl;

        test_04.set(1, '4');
        std::cout << "Array 4 contains a " << test_04.get(1) << " at index 1." << std::endl;
        //test_04.debug(4);

        int index = test_04.find('4');
        if (index != -1) {
            std::cout << "Array 4 contains a '4' at index " << index << "." << std::endl;
        } else {
            std::cout << "..problem.." << std::endl;
        }
        std::cout << std::endl;

        index = test_04.find('4', 2);
        if (index == -1) {
            std::cout << "Array 4 does not contain a '4' at/after index 2." << std::endl;
        } else {
            std::cout << "..problem.." << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Array 4 should ignore resize due to sameness:" << std::endl;
        test_04.resize(3);
        //test_04.debug(4);

        std::cout << "Array 4 should resize into a larger array due to max exceeded:" << std::endl;
        test_04.resize(6);
        //test_04.debug(4);

        std::cout << "Array 4 should resize into a smaller array:" << std::endl;
        test_04.resize(2);
        //test_04.debug(4);

        std::cout << "Array 4 should resize into a larger array:" << std::endl;
        test_04.resize(30);
        //test_04.debug(4);

        std::cout << "Array 4 should have a new element at pos 3:" << std::endl;
        test_04[2] = 'i';
        //test_04.debug(4);

        std::cout << "Array 4 should not give out of range error :" << std::endl;
        test_04[19] = 'j';
        test_04.set(19,'p');
        test_04.get(19);
        //test_04.debug(4);

        //delete test_01;
        //delete test_02;
        //delete test_03;
        //delete test_04;

        Array grade = Array();
        Array subject(4);
        Array fruit(10,'a');

        grade.set(0,'A');

        Array grade2(grade);
        grade2 = fruit;

        Array grade3(grade2);
        grade3.resize(0);

        subject.set(0,'m');
    /*
        grade.debug(1);
        subject.debug(2);
        fruit.debug(3);
        grade2.debug(4);
        grade3.debug(5);
    * /
        grade3.resize(11);
        // "xyp z"
        grade3[0] = 'x';
        grade3[1] = 'y';
        grade3[2] = 'p';
        grade3[4] = 'p';
        int ind = grade3.find('p',3);
        //grade3[ind] = 'z';
        std::cout << grade3[0] << "\n"; //x
        std::cout << grade3[1] << "\n"; //y
        std::cout << grade3[2] << "\n"; //p
        std::cout << grade3[3] << "\n"; //???
        std::cout << grade3[4] << "\n\n"; //z

        //grade3.debug(5);

        std::cout << "--1--\n";
        Array zero(0);
        std::cout << "--2--\n";
        std::cout << zero[0] << "\n";           // out of range
        std::cout << "--3--\n";
        std::cout << zero.max_size() << "\n";   // 10
        std::cout << "--4--\n";
        std::cout << zero.size() << "\n";       // 0
        std::cout << "--end--\n";
**** /
    } catch (...) {
        std::cout<<"main function has failed because of an exception."<<std::endl;
    }
*/
    ////////////////////////////////////////////////////////////////
    std::cout << "\ntester.cpp has completed execution." << std::endl;
    ////////////////////////////////////////////////////////////////

    return 0;

}
