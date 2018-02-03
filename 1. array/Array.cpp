////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Array.cpp
//  Date:           08/27/2017
//  Description:    Main implementation of the custom array class.
//                  This array only supports characters.
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
#include "Array.h"

// Ryan: Good use!
// default max length is 10
#define DEFAULT_MAX_SIZE 10

// Ryan: Use the keyword "this" in place of Array.
// Fixed: Replaced usage of "Array::" with "this->".

Array::Array (void) :
        data_ (new char[DEFAULT_MAX_SIZE+1]),
        cur_size_ (DEFAULT_MAX_SIZE),
        max_size_ (DEFAULT_MAX_SIZE) {

    // init
    // (+1 for '\0' terminator character)

    // warning
    std::cout << "Warning: Default size (" << DEFAULT_MAX_SIZE << ") set" << std::endl;

    // fill with empty spaces
    this->fill(' ');
}

Array::Array (size_t length) :
        data_ (new char[DEFAULT_MAX_SIZE+1]),
        cur_size_ (DEFAULT_MAX_SIZE),
        max_size_ (DEFAULT_MAX_SIZE) {

    // Ryan: You should check to ensure length is not 0.
    // Fixed: Checked to ensure length is not zero by initializing to default
    //        and then resizing to length later as long as length is > 0.

    // init
    // (+1 for '\0' terminator character)

    // resize or warning
    if (length > 0) {
        this->resize(length);
    } else {
        std::cout << "Warning: Default size (" << DEFAULT_MAX_SIZE << ") set." << std::endl;
    }

    // fill with empty spaces
    this->fill(' ');
}

Array::Array (size_t length, char fill) :
        data_ (new char[DEFAULT_MAX_SIZE+1]),
        cur_size_ (DEFAULT_MAX_SIZE),
        max_size_ (DEFAULT_MAX_SIZE) {

    // Ryan: You should check to ensure length is not 0.
    // Fixed: Checked to ensure length is not zero by initializing to default
    //        and then resizing to length later as long as length is > 0.

    // init
    // (+1 for '\0' terminator character)

    // resize or warning
    if (length > 0) {
        this->resize(length);
    } else {
        std::cout << "Warning: Default size (" << DEFAULT_MAX_SIZE << ") set." << std::endl;
    }

    // fill array
    this->fill(fill);
}

Array::Array (const Array & array) :
        data_ (new char[array.max_size()+1]),
        cur_size_ (array.size()),
        max_size_ (array.max_size()) {

    // init
    // (+1 for '\0' terminator character)

    // copy elements and fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = array[i];
    }
}

Array::~Array (void) {

    // release chars from memory
    delete [] this->data_;
}

const Array & Array::operator = (const Array & rhs) {

    // Ryan: Always check for self-assignment first.
    // Fixed: Checked for self assignment first by checking if the memory
    //        location of rhs is the same as self.

    // check for self assignment
    if (this == &rhs) {

        // return value this is pointing at
        return * this;
    }

    // release current chars from memory
    delete [] this->data_;

    // re-init
    // (+1 for '\0' terminator character)
    this->data_     = new char[rhs.max_size()+1];
    this->cur_size_ = rhs.size();
    this->max_size_ = rhs.max_size();

    // copy elements and fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = rhs[i];
    }

    // return value this is pointing at
    return * this;
}

char & Array::operator [] (size_t index) {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element
    return this->data_[index];
}

const char & Array::operator [] (size_t index) const {

    // Ryan: Make sure to check for out of range here as well.
    // Fixed: Checked for out of range exception here in the same way as the
    //        "non-const" version of this function.

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element that is not modifiable
    return this->data_[index];
}

char Array::get (size_t index) const {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // return element
    return this->data_[index];
}

void Array::set (size_t index, char value) {

    // exception if out of bounds
    if (index < 0 || index >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // set element
    this->data_[index] = value;
}

void Array::resize (size_t new_size) {

    // if invalid new size
    if (new_size <= 0) {

        // warning: default size set
        std::cout << "Warning: New size must be greater than 0. Resize ignored." << std::endl;
        return;
    }

    // if new size is larger than max
    if (new_size > this->max_size_) {

        // double the current max size until
        // the new size fits
        int new_max = this->bound_max(this->max_size_, new_size);

        // init array with new max size
        // (+1 for '\0' terminator character)
        char * tmp = new char[new_max+1];

        // copy old array into bigger
        size_t i = 0;
        for (i = 0; i < this->cur_size_; i++) {
            tmp[i] = this->data_[i];
        }

        // init the rest with spaces
        // (this takes care of possible "uninitialized value" errors)
        for (size_t j = i; j < new_max; j++) {
            tmp[j] = ' ';
        }

        // delete old array
        delete [] this->data_;

        // set bigger array
        this->data_ = tmp;
        this->cur_size_ = new_size;
        this->max_size_ = new_max;
        return;
    }

    // if new size is larger/smaller than the current
    if (new_size != this->cur_size_) {

        // simply change the variable
        // (memory allocated already based on max size)
        this->cur_size_ = new_size;
    }
}

int Array::find (char ch) const {

    // Ryan: Why not just use the function below here?
    // Fixed: Used "find(char,size_t)" here where size_t is always 0 to avoid
    //        rewriting code.

    // refer to find(char,size_t)
    return this->find(ch, 0);
}

int Array::find (char ch, size_t start) const {

    // exception if out of bounds
    if (start < 0 || start >= this->cur_size_) {
        throw(std::out_of_range("Error: Invalid index"));
    }

    // linear search
    for (size_t i=start; i<this->cur_size_; i++) {

        // found
        if (this->data_[i] == ch) {
            return i;
        }
    }

    // not found
    return -1;
}

bool Array::operator == (const Array & rhs) const {

    // Ryan: Always check for self-comparison first.
    // Fixed: Checked for self comparison first by checking if the memory
    //        location of rhs is the same as self.

    // check for self assignment
    if (this == &rhs) {
        return true;
    }

    // different lengths means not equal
    if (rhs.size() != this->size()) {
        return false;
    }

    // linear search
    for (size_t i=0; i<this->cur_size_; i++) {

        // elements do not match at this index
        if (this->data_[i] != rhs[i]) {
            return false;
        }
    }

    // arrays have identical content
    return true;
}

bool Array::operator != (const Array & rhs) const {

    // Ryan: Always check for self-comparison first.
    // Fixed: Checked for self comparison first by checking if the memory
    //        location of rhs is the same as self.

    // check for self assignment
    if (this == &rhs) {
        return false;
    }

    // different lengths means not equal
    if (rhs.size() != this->size()) {
        return true;
    }

    // linear search
    for (size_t i=0; i<this->cur_size_; i++) {

        // elements do not match at this index
        if (this->data_[i] != rhs[i]) {
            return true;
        }
    }

    // arrays have identical content
    return false;
}

void Array::fill (char ch) {

    // fill array
    for (size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = ch;
    }
}

int Array::bound_max (size_t max, size_t cur) {

    // double the current max size until
    // the new size fits
    int new_max = max;
    while (cur > new_max) {
        new_max *= 2;
    }

    // return new max
    return new_max;
}
