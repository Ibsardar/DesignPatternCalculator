////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Proxy_Pointer.h
//  Date:           12/08/2017
//  Description:    Headers for Proxy_Pointer class.
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

#ifndef _PROXY_POINTER_H_
#define _PROXY_POINTER_H_

/**
*   @class Proxy_Pointer
*
*   A Proxy_Pointer that represents a pointer but
*   manages its memory usage automatically. Basically
*   an std::auto_ptr.
*/
template <typename T>
class Proxy_Pointer {

public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor
    Proxy_Pointer(void);

    /**
    *   Initialization constructor
    *
    *   @param          T*              pointer of type T
    */
    Proxy_Pointer(T *);

    /**
    *   Copy constructor
    *
    *   @param          ptr             source proxy pointer
    */
    Proxy_Pointer(const Proxy_Pointer <T> &);

    /// Default destructor
    ~Proxy_Pointer(void);

    /**
    *   Sets current pointer to rhs's pointer, but also unsets rhs's pointer to
    *   null, exactly like an std::auto_ptr.
    *
    *   @return         reference to T      un-copied value
    */
    const Proxy_Pointer <T> & operator = (Proxy_Pointer <T> &);

    /**
    *   Returns reference (un-copied value) of the value pointed at
    *
    *   @return         reference to T      un-copied value
    */
    T & operator * (void);

    /**
    *   * This is a special C++ operator *
    *   Reapplies self to the result until a raw pointer is reached, and once
    *   more to access the memory referrenced by that pointer, ultimately
    *   returning the data pointed to by that pointer.
    *
    *   @return         pointer to T
    */
    T * operator -> (void);

    /**
    *   Makes the '*' operator behave like a cast and returns the underlying
    *   pointer.
    *
    *   @cast           pointer to T        casts self to T* ptr_
    */
    operator T * (void);

protected:
    /// actual pointer that is pointing to some data
    T * ptr_;
};

/// include source
#include "Proxy_Pointer.cpp"

#endif   // !defined _PROXY_POINTER_H_
