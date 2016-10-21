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
void *producer (void *arg);
void *consumer (void *arg);
void vowel(string str1);
string abc(string x);
string buffer[SIZE];
sem_t empty, full, mutex;
int in = 0, out = 0, input = 0;
string str = " ";
int emp, ful = 0, mut, arg;
pthread_t proID,conID;
int main() {
   
    
    cout << "Enter a number: ";
    cin >> input;
    srand (static_cast<int>(time(NULL)));
    while (input != 0){
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&proID, NULL, producer, (void *)arg);
   // pthread_create(&conID, NULL, consumer, (void *)arg);
    pthread_join(proID, NULL);
    //pthread_join(conID, NULL);
        input--;
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    if(input == 0){
    pthread_exit(NULL);
}
    return 0;
}

void *producer(void* arg){
    do{
       string bob; 
       string str = abc(bob); 
        
    while (ful == SIZE)
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[in] = str;
    in = (in+1)%SIZE;
    sem_post(&mutex);
    sem_post(&full);
    ful++;
        if(input<0){
        break;
    }
}while(true);

    pthread_exit(NULL);
}

void *consumer(void *arg){
    string str1;
    do{

    while (count != 0){
        str1 = buffer[out];
        out = (out+1)% SIZE;
        count--;
        vowel(str1);
    }
    sem_wait(&full);
    sem_wait(&mutex);
    buffer[out] = str;
    out = (out+1)%SIZE;
    sem_post(&mutex);
    sem_post(&empty);
    if(input<0){
        break;
    }
   }while(true);

}
string abc(string x){
    string str = x;   
    map<int,char> map1;
    map1.insert(pair<int,char>(1,'a') ),map1.insert(pair<int,char>(2,'b') );
    map1.insert(pair<int,char>(3,'c') ),map1.insert(pair<int,char>(4,'d') );
    map1.insert(pair<int,char>(5,'e') ),map1.insert(pair<int,char>(6,'f') );
    map1.insert(pair<int,char>(7,'g') ),map1.insert(pair<int,char>(8,'h') );
    map1.insert(pair<int,char>(9,'i') ),map1.insert(pair<int,char>(10,'j') );
    map1.insert(pair<int,char>(11,'k') ),map1.insert(pair<int,char>(12,'l') );
    map1.insert(pair<int,char>(12,'l') ),map1.insert(pair<int,char>(13,'m') );
    map1.insert(pair<int,char>(14,'n') ),map1.insert(pair<int,char>(15,'o') );
    map1.insert(pair<int,char>(16,'p') ),map1.insert(pair<int,char>(17,'q') );
    map1.insert(pair<int,char>(18,'r') ),map1.insert(pair<int,char>(19,'s') );
    map1.insert(pair<int,char>(20,'t') ),map1.insert(pair<int,char>(21,'u') );
    map1.insert(pair<int,char>(22,'v') ),map1.insert(pair<int,char>(23,'w') );
    map1.insert(pair<int,char>(24,'x') ),map1.insert(pair<int,char>(25,'y') );
    map1.insert(pair<int,char>(26,'z') );
    
    map<int,char>::iterator xp;
    
    char a = '\0',b = '\0',c = '\0';
    
    int count = 0, random = rand() % 26 + 1;
    
    
    while (count < 3){
        int y = random;
        if(count == 0){
            xp = map1.find(y);
            if(xp != map1.end()){
                b = xp->second;
                
                count++;
            }
        }
        else if(count == 1){
            y-= 1;
            xp = map1.find(y);
            if(xp != map1.end()){
                a = xp->second;
                count++;
            }
            else if(y<0){
                y = 26-y;
                xp = map1.find(y);
                if(xp != map1.end()){
                    a = xp->second;
                    count++;
                }
            }
        }
        else if(count == 2){
            y+= 1;
            xp = map1.find(y);
            if(xp != map1.end()){
                c = xp->second;
                
                count++;
            }
            else if(y>26){
                y = y-26;
                xp = map1.find(y);
                if(xp != map1.end()){
                    c = xp->second;
                    
                    count++;
                }
            }
        }
    }
    str = (str + a) + (str + b) + (str + c);
    printf("Producer: %s\n", str.c_str());
    return str;

}
void vowel(string str1){
   int vowCOUNT = 0;
    for (int place = 0; place < 3; place++){
        if(str[place] == 'a' | str[place] == 'e' | str[place] == 'i'| str[place] == 'o'| str[place] == 'u' ){
           vowCOUNT++;
        }
    }
    printf("Consumer: %d\n", vowCOUNT);
}