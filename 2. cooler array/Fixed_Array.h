////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Fixed_Array.h
//  Date:           10/09/2017
//  Description:    Headers for Fixed_Array class.
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

#ifndef _FIXED_ARRAY_H_
#define _FIXED_ARRAY_H_

#include "Base_Array.h"

// Ryan: A better approach would be to create a Base Array to inherit from
// this will resolve the problem of inheriting the resize function from our
// more dynamic Array class.
// Fixed: Created Base_Array class; Fixed_Array now inherits from it.

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Base_Array so it can inherit of
 * the Base_Array's class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Base_Array <T> {

public:
    /// Default constructor.
    Fixed_Array (void);

    /**
    * Copy constructor.
    *
    * @param[in]      arr        Source array
    */
    Fixed_Array (const Fixed_Array <T, N> & arr);

    /**
    * Initializing constructor. The source array can be of any size
    * as long as they are of the same type.
    *
    * @param[in]      arr        Source array
    */
    template <size_t M>
    Fixed_Array (const Fixed_Array <T, M> & arr);

    /**
    * Initializing constructor. Fills the contents of the
    * array with the specified \a fill value.
    *
    * @param[in]      fill       The fill value.
    */
    Fixed_Array (T fill);

    /// Destructor.
    ~Fixed_Array (void);

    /**
    * Assignment operator
    *
    * @param[in]      rhs        Right-hand side of operator.
    */
    const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);

    /**
    * Assignment operator
    *
    * @param[in]      rhs        Right-hand side of operator.
    */
    template <size_t M>
    const Fixed_Array & operator = (const Fixed_Array <T, M> & rhs);
};

// include the source file since template class
#include "Fixed_Array.cpp"

#endif   // !defined _FIXED_ARRAY_H_
