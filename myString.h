//
//  main.hpp
//  maomaoshibendan
//
//  Created by J-lo on 2/5/17.
//  Copyright © 2017 JL. All rights reserved.
//

#ifndef myString_h
#define myString_h

#include <stdio.h>
#include <iostream>

using namespace std;

class myString {
private:
    static const size_t npos = -1; // returned when something is not found
    int len_;  // length of the string
    char* chars_; // pointer to cstring array
    
    // Helper functions
    // allocator
    void alloc(char* chars_) {
        chars_ = new char[len_];
    }
    
    // array copier
    void copy(const myString& sourcestr) {
        for (int i = 0; i < len_; i++) {
            chars_[i] = sourcestr.chars_[i];
            std::cout << chars_[i];
        }
    }
    
    // separator
    void ws () {
        std::cout << " ";
    }
    
public:

    // Constructors
    // default constructor
    myString();
    
    // character array constructor
    myString(char* init);
    
    // single-character constructor
    myString(char c);
    
    // copy constructor
    myString(const myString& sourcestr);
    
    // assignment operator overloading
    myString& operator=(const myString& sourcestr); // for chained assignment
    
//    // destructor
//    ~myString();
    

    
    // Getters
    // length of string
    int length() {
        return len_;
    }
    
    // length of const string
    int length() const {
        return len_;
    }

    // reference to ith character
    char& at(int i) {
        return chars_[i];
    }
    
    // reference to ith of a const
    char& at(int i) const {
        return chars_[i];
    }

//    // substring
//    myString substr(int k, int n);

    // substring const
    myString substr(int k, int n) const;

//
//    // Setters
//    // erase
//    myString& erase(int k, int n); // returns ref to new string
//    
//    // insert
//    myString& insert(int k, const myString& s); // returns ref to new string
//    
    
    // find
    int find(const myString& s) const;
    
    friend istream& getline(istream& is, myString& s);
};

#endif /* myString_h */
