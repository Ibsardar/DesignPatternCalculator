////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       driver.cpp
//  Date:           09/26/2017
//  Description:    Main testing for Assignment #2.
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

#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

using std::cout;
using std::endl;

/// Too lazy to make template functions:

//
//  parint - print Array<int>
//
void parint(Array<int>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
//
//  parchr - print Array<char>
//
void parchr(Array<char>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
//
//  pardub - print Array<double>
//
void pardub(Array<double>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

/***
//
//  pfaint - print Fixed_Array<int>
//
void pfaint(Fixed_Array<int,size_t>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}
***/

//
//  pstint - print Stack<int>
//
void pstint(Stack<int>& a) {
    cout << "<-> [";
    while (!a.is_empty()) {
        cout << a.top();
        a.pop();
        if (a.size())
            cout << ",";
    }
    cout << "]" << endl;
}

//
//  pquint - print Queue<int>
//
void pstint(Queue<int>& a) {
    cout << "<- [";
    while (!a.is_empty()) {
        cout << a.dequeue();
        if (a.size())
            cout << ",";
    }
    cout << "] <-" << endl;
}

//
// main
//
int main (int argc, char * argv []) {

    cout << "Hello, I am starting successfully." << endl;


    //***    Array Tests
    try {

        Array <int>    arr1   = Array <int>    ();
        Array <char>   arr2   = Array <char>   (11);
        Array <char>   arr22  = Array <char>   (2);
        Array <char>   arr222 = Array <char>   (0);
        Array <double> arr3   = Array <double> (3,3.14);
        Array <double> arr33  = Array <double> (11,0.123);
        Array <double> arr333 = Array <double> (0,45.67);
        Array <int>    arr4   = Array <int>    (arr1);
        //Array <int>    arr44  = Array <int>    (arr2); // should be error
        Array <double> arr444 = Array <double> (arr3);

        cout << arr3[0] << endl;

        arr1 = arr4; // note: same
        arr2 = arr2; // note: same
        arr2 = arr22; // note: arr2 is 11 blanks, arr22 is 2 blanks, arr2 IS NOW 2 blanks
        arr22 = arr222; // note: arr222 is empty, arr22 HAS BECOME EMPTY
        arr333 = arr3; // note: arr333 empty, arr3 is 3 3.14s, arr333 IS NOW 3 3.14s
        arr3 = arr33; // note: arr33 is 11 0.123s, arr3 IS NOW 11 0.123s

        cout << "pre-tests:" << endl;
        cout << (arr1 == arr4 ) <<  (arr4 != arr1 ) << endl; // 1, 0
        cout << (arr1 == arr1 ) <<  (arr1 != arr1 ) << endl; // 1, 0
        //cout << (arr1 == arr2 ) <<  (arr2 != arr1 ) << endl; // should be error
        cout << (arr2 == arr22)  << ( arr22 != arr2) << endl; // 0, 1
        cout << "arr type 1s:" << endl;
/*        parint(arr1);
        cout << "arr type 2s:" << endl;
        parchr(arr2);
        parchr(arr22);
        parchr(arr222);
        cout << "arr type 3s:" << endl;
        pardub(arr3);
        pardub(arr33);
        pardub(arr333);
        cout << "arr type 4s:" << endl;
        parint(arr4);
        pardub(arr444);*/

        arr1.resize(11);
        arr1.fill(999);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1.set(2,30);
        //parint(arr1);
        arr1.resize(1);
        //parint(arr1);
        arr1.resize(0); // should be ignored
        //parint(arr1);
        //arr1.set(1,22); // should be exception
        //arr1.set(0,11); // should be exception
        //parint(arr1);
        //***/

    } catch (const std::exception &e) {

        // catch and print exception
        std::cerr << "EXCEPTION:\t" << e.what() << endl;
    }
    //***/

    /***    Fixed Array Tests
    try {

        Fixed_Array<int,3> arr1 = Fixed_Array<int,3> ();
        Fixed_Array<int,0> arr2 = Fixed_Array<int,0> (arr1);
        Fixed_Array<int,1> arr3 = Fixed_Array<int,1> (arr2);
        Fixed_Array<int,11> arr4 = Fixed_Array<int,11> (999);

        Fixed_Array<int,3> arr11 = Fixed_Array<int,3> (12345);
        arr11[0] = 54321;

        arr1 = arr11;
        arr2 = arr11;
        arr3 = arr11;
        arr4 = arr11;

        cout << "array 1:" << endl;
        cout << "[0]: " << arr1[0] << endl;
        cout << "[2]: " << arr1[2] << endl;
        //cout << "[3]: " << arr1[3] << endl; // should be exception
        cout << "array 2:" << endl;
        cout << "[0]: " << arr2[0] << endl;
        cout << "[2]: " << arr2[2] << endl;
        cout << "[3]: " << arr2[3] << endl;
        cout << "[9]: " << arr2[9] << endl;
        //cout << "[10]: " << arr2[10] << endl; // should be exception
        cout << "array 3:" << endl;
        cout << "[0]: " << arr3[0] << endl;
        //cout << "[1]: " << arr3[1] << endl; // should be exception
        cout << "array 4:" << endl;
        cout << "[0]: " << arr4[0] << endl;
        cout << "[10]: " << arr4[10] << endl;
        //cout << "[11]: " << arr4[11] << endl; // should be exception



    } catch (const std::exception &e) {

        // catch and print exception
        std::cerr << "EXCEPTION:\t" << e.what() << endl;
    }
    //***/

    //***    Stack Test
    try {

        Stack<int> s1 = Stack<int> ();
        cout<<"step 0"<<endl;
        s1.push(0);
        s1.push(11);
        cout<<"step 1"<<endl;
        s1.pop();
        s1.pop();
        cout<<"step 2"<<endl;
        s1.push(222);
        s1.push(3333);
        cout<<"step 3"<<endl;
        s1.pop();
        cout<<"step 4"<<endl;
        s1.push(44444);
        cout<<"step 5"<<endl;
        s1.clear();
        cout << "step 6" << endl;
        Stack<int> s2 = Stack<int> (s1);
        s2.push(1);
        s2.push(22);
        s2.pop();
        s2.push(2);
        cout << "step 7" << endl;
        Stack<int> s3 = Stack<int> (s2);
        cout << "step 8" << endl;
        s3.push(3);
        cout << "step 9" << endl;
        Stack<int> s4 = Stack<int> ();
        cout << "step 10" << endl;
        s4.push(1);
        s4.push(2);
        s4.push(3);
        cout << "step 11" << endl;

        assert(s1.is_empty());
        assert(!s2.is_empty());
        assert(!s3.is_empty());
        assert(!s4.is_empty());
        cout << "step 12" << endl;

        Array<int> temp4 = Array<int> (3);
        temp4[2] = s4.top(); s4.pop();
        temp4[1] = s4.top(); s4.pop();
        temp4[0] = s4.top(); s4.pop();
        Array<int> temp3 = Array<int> (3);
        temp3[2] = s3.top(); s3.pop();
        temp3[1] = s3.top(); s3.pop();
        temp3[0] = s3.top(); s3.pop();
        Array<int> temp2 = Array<int> (2);
        temp2[1] = s2.top(); s2.pop();
        temp2[0] = s2.top(); s2.pop();
        //cout << "Something will break under me..." << endl;
        //cout << "s2 TOP: " << s2.top() << endl; // should be exception
        //temp2[0] = s2.top(); // should be exception
        //s2.pop(); // should be exception
        assert(temp4[0]==temp3[0] && temp4[1]==temp3[1] && temp4[2]==temp3[2]);
        assert(temp4[0]==temp2[0] && temp4[1]==temp2[1]);
        cout << "step 13" << endl;

    } catch (const std::exception &e) {

        // catch and print exception
        std::cerr << "EXCEPTION:\t" << e.what() << endl;
    }
    //***/

    //***    Queue Test
    try {

        Queue<int> q1 = Queue<int> ();

        q1.enqueue(10); // SHOULD BE: head=0, tail=0, qsize=1, asize=1, max=10
        cout<<"step 0i"<<endl;
        q1.dequeue(); // SHOULD BE: head=1, tail=0, qsize=0, asize=1, max=10
        cout<<"step 1i"<<endl;
        q1.enqueue(11); // SHOULD BE: head=0, tail=0, qsize=1, asize=1, max=10
        cout<<"step 2i"<<endl;
        q1.enqueue(12); // SHOULD BE: head=0, tail=1, qsize=2, asize=2, max=10
        q1.clear();

        cout<<"step 0"<<endl;
        q1.enqueue(0);
        q1.enqueue(11);
        cout<<"step 1"<<endl;
        q1.dequeue();
        q1.dequeue();
        cout<<"step 2"<<endl;
        q1.enqueue(222);
        q1.enqueue(3333);
        cout<<"step 3"<<endl;
        q1.dequeue();
        cout<<"step 4"<<endl;
        q1.enqueue(44444);
        cout<<"step 5"<<endl;
        q1.clear();
        cout << "step 6" << endl;
        Queue<int> q2 = Queue<int> (q1);
        q2.enqueue(1);
        q2.enqueue(22);
        q2.dequeue();
        q2.enqueue(2);
        cout << "step 7" << endl;
        Queue<int> q3 = Queue<int> (q2);
        cout << "step 8" << endl;
        q3.enqueue(3);
        cout << "step 9" << endl;
        Queue<int> q4 = Queue<int> ();
        cout << "step 10" << endl;
        q4.enqueue(22);
        q4.enqueue(2);
        q4.enqueue(3);
        cout << "step 11" << endl;

        assert(q1.is_empty());
        assert(!q2.is_empty());
        assert(!q3.is_empty());
        assert(!q4.is_empty());
        cout << "step 12" << endl;

        Queue<int> q5 = Queue<int> (q3);
        Queue<int> q6 = Queue<int> ();
        q6 = q5;
        assert(q5.dequeue() == q6.dequeue());
        assert(q5.dequeue() == q6.dequeue());
        assert(q5.dequeue() == q6.dequeue());
        //assert(q5.dequeue() == q6.dequeue()); // should be exception
        cout << "step 13" << endl;

        Array<int> temp4 = Array<int> (3);
        temp4[0] = q4.dequeue();
        temp4[1] = q4.dequeue();
        temp4[2] = q4.dequeue();
        Array<int> temp3 = Array<int> (3);
        temp3[0] = q3.dequeue();
        temp3[1] = q3.dequeue();
        temp3[2] = q3.dequeue();
        Array<int> temp2 = Array<int> (2);
        temp2[0] = q2.dequeue();
        temp2[1] = q2.dequeue();
        assert(temp4[0]==temp3[0] && temp4[1]==temp3[1] && temp4[2]==temp3[2]);
        assert(temp4[0]==temp2[0] && temp4[1]==temp2[1]);
        cout << "step 14" << endl;

    } catch (const std::exception &e) {

        // catch and print exception
        std::cerr << "EXCEPTION:\t" << e.what() << endl;
    }
    //***/

    cout << "Hello, I am ending successfully." << endl;
}
