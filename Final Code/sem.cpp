/*
* Created by Chris West started 11/03/16 - 11/15/16.
* Copyright © 2016 Chris West. All rights reserved.
*/
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

string createMessage(string message);
string buffer[SIZE];
sem_t empty, full, mutex;

int in = 0, out = 0, input = 0, counter = 0;
int emp, ful = 0, mut, arg;
pthread_t proID,conID;
int main() {
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
        string message = createMessage("");
        
        while (counter == SIZE);
        
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = message;
        in = (in+1)%SIZE;
        sem_post(&mutex);
        sem_post(&full);
        p++;
        counter++;
        if(p == input){
            break;  
        }
        
    } while(true);   
    
}

void *consumer(void *arg){
    string message;
    int count = 0;
    do{
        
        while (counter == 0);
        
        sem_wait(&full);
        sem_wait(&mutex);
        message = buffer[out];
        cout << "Consumer: " << message << endl;
        int vowelCount = vowel(message);
        if (vowel(message) > 0)
            cout << "There is " << vowelCount << " vowel." << endl;
        else
            cout << "No vowels." << endl;
        out = (out+1)% SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        counter--;
        count++;
        
        
        if(count == input){
            break;
        }
    } while(true);
    
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
    cout << "Producer: " << message << ", " << random << endl;
    return message;
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
