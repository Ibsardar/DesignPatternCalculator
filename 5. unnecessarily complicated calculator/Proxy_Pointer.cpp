////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Proxy_Pointer.cpp
//  Date:           12/08/2017
//  Description:    Main implementation for Proxy_Pointer class.
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

//#include "Proxy_Pointer.h" //................................................................. del this

//
//  default constructor
//
template <typename T>
Proxy_Pointer <T>::Proxy_Pointer (void) : ptr_(NULL) {

    //...
}

//
//  initialization constructor
//
template <typename T>
Proxy_Pointer <T>::Proxy_Pointer (T * ptr) : ptr_(ptr) {

    //...
}

//
//  copy constructor
//
template <typename T>
Proxy_Pointer <T>::Proxy_Pointer (const Proxy_Pointer <T> & proxy_ptr) :
        ptr_ (proxy_ptr.ptr_) {

    //...
}

//
//  default destructor
//
template <typename T>
Proxy_Pointer <T>::~Proxy_Pointer (void) {

    // auto delete my pointer
    if (this->ptr_ != NULL)
        delete this->ptr_;
}

//
// equals operator
//
template <typename T>
const Proxy_Pointer <T> & Proxy_Pointer <T>::operator = (Proxy_Pointer <T> & rhs) {

    // check self assignment
    if (this == &rhs)
        return *this;

    // delete current ptr
    if (this->ptr_ != NULL)
        delete this->ptr_;

    // set new ptr
    //this->ptr_ = rhs;
    this->ptr_ = rhs.ptr_;

    // nullify rhs's ptr (or else we will get double delete errors later)
    rhs.ptr_ = NULL;

    // return self
    return *this;
}

//
//  * operator
//
template <typename T>
T & Proxy_Pointer <T>::operator * (void) {

    // return data pointer is pointing at
    return *(this->ptr_);
}

//
//  -> operator
//
template <typename T>
T * Proxy_Pointer <T>::operator -> (void) {

    // return the pointer
    return this->ptr_;
}

//
//  * cast
//
template <typename T>
Proxy_Pointer <T>::operator T * (void) {

    // return the pointer
    return this->ptr_;
}
