////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Proxy_Array_Pointer.cpp
//  Date:           12/10/2017
//  Description:    Main implementation for Proxy_Array_Pointer class.
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
//  default constructor
//
template <typename T>
Proxy_Array_Pointer <T>::Proxy_Array_Pointer (void) : ptr_(NULL) {

    //...
}

//
//  initialization constructor
//
template <typename T>
Proxy_Array_Pointer <T>::Proxy_Array_Pointer (T * ptr) : ptr_(ptr) {

    //...
}

//
//  copy constructor
//
template <typename T>
Proxy_Array_Pointer <T>::Proxy_Array_Pointer (
            const Proxy_Array_Pointer <T> & proxy_ptr) : ptr_(proxy_ptr.ptr_) {

    //...
}

//
//  default destructor
//
template <typename T>
Proxy_Array_Pointer <T>::~Proxy_Array_Pointer (void) {

    // auto delete my array pointer
    if (this->ptr_ != NULL)
        delete [] this->ptr_;
}

//
// equals operator
//
template <typename T>
const Proxy_Array_Pointer <T> & Proxy_Array_Pointer <T>::operator = (
        Proxy_Array_Pointer <T> & rhs) {

    // check self assignment
    if (this == &rhs)
        return *this;

    // delete current array memory
    delete [] this->ptr_;

    // re-init my pointer to rhs's pointer
    //this->ptr_ = rhs;
    this->ptr_ = rhs.ptr_;

    // nullify rhs's ptr (or else we will get double delete errors later)
    rhs.ptr_ = NULL;

    // return self
    return *this;
}

//
//  array operator
//
template <typename T>
T & Proxy_Array_Pointer <T>::operator [] (size_t index) {

    // return data at index of array pointer
    return this->ptr_[index];
}

//
//  * operator
//
template <typename T>
T & Proxy_Array_Pointer <T>::operator * (void) {

    // return data pointer is pointing at
    return *(this->ptr_);
}

//
//  -> operator
//
template <typename T>
T * Proxy_Array_Pointer <T>::operator -> (void) {

    // return the pointer
    return this->ptr_;
}

//
//  * cast
//
template <typename T>
Proxy_Array_Pointer <T>::operator T * (void) {

    // return the pointer
    return this->ptr_;
}
