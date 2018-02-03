////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Iterator.h
//  Date:           12/07/2017
//  Description:    Abstract Iterator class.
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

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

/**
*   @class Iterator
*
*   An abstract Iterator to iterate over list-sytle
*   data structures
*/
template <typename T>
class Iterator {

public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor (deleted: this is because iterator will expect a
    ///                               reference to iterate over)
    Iterator(void) {}// = delete;

    /// Default destructor (virtual)
    virtual ~Iterator(void) {}

    /// Copy constructor (deleted)
    Iterator(const Iterator &) = delete;

    /// Assignment operator (deleted)
    const Iterator & operator = (const Iterator &) = delete;

    /**
    *   Indicates if iterator has finished iterating
    *
    *   @retval         true            No more possible teratorations
    *   @retval         false           One or more iterations left
    */
    virtual bool is_done(void) = 0;

    /**
    *   Advances the iterator to the next element
    */
    virtual void advance(void) = 0;

    /**
    *   Returns value of current element iterator has reached
    *
    *   @return         reference to T      current value at
    */
    virtual T & operator * (void) = 0;

    /**
    *   * This is a special C++ operator *
    *   Reapplies self to the result until a raw pointer is reached, and once
    *   more to access the memory referrenced by that pointer, ultimately
    *   returning the data pointed to by that pointer.
    *
    *   @return         pointer to T
    */
    virtual T * operator -> (void) = 0;
};

#endif   // !defined _ITERATOR_H_
