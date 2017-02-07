//
//  main.cpp
//  maomaoshibendan
//
//  Created by J-lo on 2/5/17.
//  Copyright © 2017 JL. All rights reserved.
//

#include <iostream>
#include "myString.h"
#include "myString.cc"


// MAKE SURE TO FREE UP SPACE AT THE END OF THE PROGRAM!

int main () {
    // char ch = 's';
    
    char buff[6] = {'h', 'e', 'l', 'l', 'o'};
    char *init = buff;
    
    const myString one = myString(init);
    myString two = myString(init);
    two = myString(one);
//    myString third = myString(ch);
//    
//    myString four = myString(init);
//    four = third = one;
//    
//    std::cout << one.length();
//    std::cout << two.length();
//    
//    std::cout << one.at(3);
//    std::cout << two.at(3);
//    
//    two.substr(1,3);
//    one.substr(1,3);
    
    char arr[3] = {'l', 'l'};
    std::cout << one.find(two);
    std::cout << two.find(arr);
    
    return 0;
}
