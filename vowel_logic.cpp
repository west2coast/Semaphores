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
void *producer (void *);
void *consumer (void *);
void vowel(string str1);
string abc(string x);
string buffer[SIZE];
sem_t empty, full, mutex;

int in = 0, out = 0, input = 0, counter = 0;
string str = " ";
int emp, ful = 0, mut, arg;
pthread_t proID,conID;
int main() {
    cout << "Enter a number: ";
    cin >> input;
    if (input == 0){
        return 0;
    }

void vowel(string str1){
  char vowels[] = new char[5](); 
   int vowCOUNT = 0;
    for (int place = 0; place < 3; place++){
        if(str1[place] == 'a' | str1[place] == 'e' | str1[place] == 'i'| str1[place] == 'o'| str1[place] == 'u' ){
           vowCOUNT++;
        }
    }
    cout << "Consumer: " << vowCOUNT << endl;
}