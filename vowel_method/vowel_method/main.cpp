    //
    //  main.cpp
    //  Semaphores
    //
    //  Created by Chris West due 11/3/15.
    //  Copyright © 2015 Chris West. All rights reserved.
    //

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <map>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define SIZE 2
using namespace std;


int in = 0, out = 0, input = 0, counter = 0;
string str = " ";
int vowel(string message){
    char vowels[] = {'a','e','i','o','u'};
    int vowCount = 0;
    for (char letter: vowels){
        int index = 0;
        while (index < message.size()){
            if (message.at(index) == letter)
                vowCount++;
            index++;
        }
    }
    
    return vowCount;
}
string createMessage(string message){
    int random = rand() % 26 + 1; // number % 26
    int letter1 = (random - 1) % 27, letter2 = (random) % 27 , letter3 = (random + 1) % 27;
    if (letter1 == 0)
        letter1 = 26;
    if (letter3 == 0)
        letter3 = 1;
    message += (char(letter1 + 96)), message += (char(letter2 + 96)), message += (char(letter3 + 96));
    cout << "first " << letter1 << " second " << letter2 << " third " << letter3 << " random " << random << endl;
    return message;
}
int main() {
    srand (static_cast<int>(time(NULL)));
    while( 0 < 1){
        
    string message = createMessage("");
    cout << message << endl;
    cout << "Vowels: " << vowel(message) << endl;
    }
}
