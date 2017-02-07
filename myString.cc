//
//  main.cpp
//  maomaoshibendan
//
//  Created by J-lo on 2/5/17.
//  Copyright © 2017 JL. All rights reserved.
//

#include "myString.h"
#include <iostream>


myString::myString(char *init) {
    len_ = 0;
    
    // check length of init; len_ increments until loop reaches null character
    while (init[len_] != '\0') {
        len_++;
    }
    
    // allocate space and copy init into chars_
    chars_ = new char[len_];
    
    // copy array
    for (int i = 0; i < len_+1; i++) {
        chars_[i] = init[i];
        std::cout << chars_[i];
    }
    
    ws();
}

myString::myString(const myString& sourcestr) {
    // this constructor is for existing objects only.
    // check if sourcestr is empty
    if (sourcestr.len_ == 0) {
        chars_ = NULL;
    }
    
    // else, copy sourcestr into chars_
    else {
        len_ = sourcestr.len_;
        alloc(chars_);
        copy(sourcestr);
    }
    ws();
    
    // skipped a line?
}

myString::myString(char c) {
    if (c == '\0') {
        chars_ = NULL;
    } else {
        len_ = 2;
        chars_ = new char[len_]; // why doesn't alloc() work here?
        chars_[0] = c;
        std::cout << chars_;
    }
    ws();
}

myString& myString::operator=(const myString& sourcestr) {
    
    // if existing chars array is not empty, delete existing chars
    if (chars_ != 0) {
        delete[] chars_;
    }
    
    // set len_ to new len_ and allocate memory
    len_ = sourcestr.len_;
    alloc(chars_);
   
    copy(sourcestr);
    ws();
    
    // return dereferenced pointer to array
    return *this;
}

//myString::~myString() {
//    if (len_ > 0)
//        delete [] chars_;
//}

//myString myString::substr(int k, int n) {
//    if ((k >= len_) || (k + n > len_)) {
//        std::cerr << "Index out of bound";
//        return *this;
//    } else {
//        char* arr = new char[n];
//        for (int i = k; i < n+1; i++) {
//            arr[i] = chars_[i];
//        }
//        
//        myString a = myString(arr);
//        for (int i = 0; i < a.len_; i++) {
//            std::cout << arr[i];
//        }
//        return a;
//    }
//}

myString myString::substr(int k, int n) const {
    // check
    if ((k >= len_) || (n >= len_) || (n - k >= len_)) {
        std::cerr << "Index out of bound";
        return *this;
    } else {
        char* newchars;
        newchars = new char[len_];
        for (int i = k; i < n+1; i++) {
            newchars[i] = chars_[i];
        }
        
        myString a = myString(newchars);
        for (int i = 0; i < a.len_; i++) {
            std::cout << newchars[i];
        }
        return a;
    }
}

int myString::find(const myString& s) const {
    size_t m = s.len_;
    size_t n = len_;
    // check if s is too long
    if (m > n) {
        std::cerr << "s is too long";
    } else {
        // start at each and find mismatch (brute force)
        for (int i = 0; i < (n-m)+1; i++) {
            int j = 0;
            while ((j < m) && (s.chars_[j] == chars_[i + j])) { //
                j++;
            }
            
            if (j == m) {
                return i; // return position in this
            }
            
            // if j != m, shift to next ith char in s.chars_
        }
        
    }
    return static_cast<int>(myString::npos);
}

istream& getline(istream& is, myString& s)
{
    char c;
    int size = 0;
    char *s_ptr = new char [size];
    
    while(is.get(c) && c!='\n')
    {
        size++;
        char *temp = s_ptr;
        s_ptr = new char [size];
        for (int i=0; i<size; i++)
        {
            s_ptr[i] = temp[i];
        }
        s_ptr[size] = c;
        
        delete [] temp;
        temp = nullptr;
    }
    return is;
}

