////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Array.inl
//  Date:           08/27/2017
//  Description:    Inline functions and templates for the custom array class.
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

// Ryan: Use the keyword "this" in place of Array.
// Fixed: Replaced usage of "Array::" with "this->".

inline
size_t Array::size (void) const {
    return this->cur_size_;
}

// Ryan: Use the keyword "this" in place of Array.
// Fixed: Replaced usage of "Array::" with "this->".

inline
size_t Array::max_size (void) const {
    return this->max_size_;
}
