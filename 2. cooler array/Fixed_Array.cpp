////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Fixed_Array.cpp
//  Date:           10/09/2017
//  Description:    Main implementation for Fixed_Array class.
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
// Fixed_Array - default constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) :
        Base_Array <T> (N) {

    //...
}

//
// Fixed_Array - copy constructor (same size)
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr) :
        Base_Array <T> (arr) {

    //...
}

//
// Fixed_Array - copy constructor (any size)
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr) :
        Base_Array <T> (N) {

    // cap input array size to N
    size_t L = N;
    if (M < N)
        L = M;

    // copy L values of input array into self
    for (int i=0; i<L; i++)
        this->set(i,arr[i]);
}

//
// Fixed_Array - fill constructor
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill) :
        Base_Array <T> (N, fill) {

    //...
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void) {

    //... parent's destructor called automatically after child's
}

//
// operator = (same size)
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs) {

    // Ryan: Do you really intend to get the reference of a reference here?
    // Fixed: dereferenced 'this' instead of taking the reference of 'rhs'.

    // check for self assignment
    if (*this == rhs) {

        // return value this is pointing at
        return * this;
    }

    // copy values of input array into self
    for (int i=0; i<N; i++)
        this->set(i,rhs[i]);

    // return value this is pointing at
    return * this;
}

//
// operator = (any size)
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs) {

    // check for self assignment
    if (*this == rhs) {

        // return value this is pointing at
        return * this;
    }

    // cap input array size to N
    size_t L = N;
    if (M < N)
        L = M;

    // copy L values of input array into self
    for (int i=0; i<L; i++)
        this->set(i,rhs[i]);

    // return value this is pointing at
    return * this;
}
