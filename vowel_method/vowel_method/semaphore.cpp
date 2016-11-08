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
int vowel(string message);
    //string abc(string x);
string createMessage(string message);
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
    srand (static_cast<int>(time(NULL)));
    sem_init(&empty, 2, 1);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&proID, NULL, producer, NULL);
    pthread_create(&conID, NULL, consumer, NULL);
    pthread_join(proID, NULL);
    pthread_join(conID, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    pthread_exit(NULL);
    return 0;
}

void *producer(void* arg){
    int p = 0;
    do{
        string bob;
        string str = abc(bob);
        
        while (counter == SIZE);
        
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = str;
        in = (in+1)%SIZE;
        sem_post(&mutex);
        sem_post(&full);
        p++;
        counter++;
        if(p==input){
            break;
            
        }
        
    }while(true);
    
    
}

void *consumer(void *arg){
    string str1;
    int c = 0;
    do{
        
        while (counter == 0);
        
        sem_wait(&full);
        sem_wait(&mutex);
        str1 = buffer[out];
        vowel(str1);
        out = (out+1)% SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        counter--;
        c++;
        
        
        if(c == input){
            
            break;
        }
    }while(true);
    
    pthread_exit(NULL);
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
//}    str = (str + a) + (str + b) + (str + c);
//    printf("Producer: %s\n", str.c_str());
//    return str;
    
}
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
