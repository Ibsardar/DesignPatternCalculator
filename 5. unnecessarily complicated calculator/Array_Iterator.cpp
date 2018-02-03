////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Array_Iterator.cpp
//  Date:           12/07/2017
//  Description:    Main implementation of Array_Iterator class.
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

//
//  initialization constructor (array only)
//
template <typename T>
Array_Iterator <T>::Array_Iterator(const Array <T> & arr) : array_(arr), index_(0) {

    //...
}

//
//  initialization constructor (array & starting index)
//
template <typename T>
Array_Iterator <T>::Array_Iterator(const Array <T> & arr, size_t i) : array_(arr),
        index_(i) {

    //...
}

//
//  default destructor
//
template <typename T>
Array_Iterator <T>::~Array_Iterator(void) {

    //...
}

//
//  is_done
//
template <typename T>
bool Array_Iterator <T>::is_done(void) {

    // done if index is at or past end of array
    return this->index_ >= this->array_.size();
}

//
//  advance
//
template <typename T>
void Array_Iterator <T>::advance(void) {

    // proceed to next element
    ++this->index_;
}

//
//  * operator
//
template <typename T>
T & Array_Iterator <T>::operator * (void) {

    // return current value iterator is at (in the array)
    return this->array_.data_[this->index_];
}

//
//  -> operator
//
template <typename T>
T * Array_Iterator <T>::operator -> (void) {

    // return current reference of the value iterator is at (in the array)
    return &(this->array_.data_[this->index_]);
}
