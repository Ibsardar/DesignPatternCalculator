////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       driver.cpp
//  Date:           10/17/2017
//  Description:    Main testing for Assignment #3.
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
#include <cstdlib>
#include <assert.h>

#include "Client.h"

using std::cout;
using std::endl;

//
// main
//
int main (int argc, char * argv []) {

    //cout << "Hello, I am starting successfully." << endl;

    // run main menu
    Client calculator;
    calculator.run();

    //cout << "\nHello, I am ending successfully." << endl;
}
