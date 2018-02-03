////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Array_Iterator.h
//  Date:           12/07/2017
//  Description:    Abstract Array_Iterator class.
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

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Iterator.h"
#include "Array.h"

/**
*   @class Array_Iterator
*   @friend of @class Array
*
*   An Array_Iterator to iterate over Arrays
*/
template <typename T>
class Array_Iterator : public Iterator <T> {

public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor (deleted: this is because iterator will expect a
    ///                               reference to iterate over)
    Array_Iterator(void) = delete;

    /// Default destructor
    ~Array_Iterator(void);

    /**
    *   Initialization constructor : array only
    *
    *   param[in]       array           reference of array
    */
    Array_Iterator(const Array <T> &);

    /**
    *   Initialization constructor : array and index
    *
    *   param[in]       array           reference of array
    *   param[in]       size_t          starting index of iterator
    */
    Array_Iterator(const Array <T> &, size_t);

    /**
    *   Indicates if iterator has finished iterating
    *
    *   @retval         true            No more possible teratorations
    *   @retval         false           One or more iterations left
    */
    bool is_done(void);

    /**
    *   Advances the iterator to the next element
    */
    void advance(void);

    /**
    *   Returns value of current element iterator has reached
    *
    *   @return         reference to T      current value at
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

private:

    /// Pointer to the Array to be iterated over
    const Array <T> & array_;

    /// index of iteration
    size_t index_;
};

/// include sources
#include "Array_Iterator.cpp"

#endif   // !defined _ARRAY_ITERATOR_H_
