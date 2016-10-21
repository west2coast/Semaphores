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
#include <mach/task.h>
#define SIZE 2
using namespace std;
void *producer (void *arg);
void *consumer (void *arg);

string buffer[SIZE];
sem_t empty, full, mutex;
pthread_t proID,conID;
int main() {
    int input = 0;
    
    cout << "Enter a number: ";
    cin >> input;
    srand (static_cast<int>(time(NULL)));
    while (input != 0){
    sem_init(&empty, 0, 2);
    sem_init(&full, 0, 0);
   // sem_init(&mutex, 0, 1);
    pthread_create(&proID, NULL, producer, NULL);
    
    pthread_create(&conID, NULL, consumer, NULL);
    pthread_join(proID, NULL);
    pthread_join(conID, NULL);
        input--;
    }
    
}

void *producer(void* arg){
    
    char abc[3];
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
    
    map<int,char>::iterator x;
    
    char a = '\0',b = '\0',c = '\0';
    int count = 0, random = rand() % 26 + 1;
    
    
    while (count < 3){
        int y = random;
        if(count == 0){
            x = map1.find(y);
            if(x != map1.end()){
                b = x->second;
                abc[1] = b;
                count++;
            }
        }
        else if(count == 1){
            y-= 1;
            x = map1.find(y);
            if(x != map1.end()){
                a = x->second;
                abc[0] = a;
                count++;
            }
            else if(y<0){
                y = 26-y;
                x = map1.find(y);
                if(x != map1.end()){
                    a = x->second;
                    abc[0] = a;
                    count++;
                }
            }
        }
        else if(count == 2){
            y+= 1;
            x = map1.find(y);
            if(x != map1.end()){
                c = x->second;
                abc[2] = c;
                count++;
            }
            else if(y>26){
                y = y-26;
                x = map1.find(y);
                if(x != map1.end()){
                    c = x->second;
                    abc[2] = c;
                    count++;
                }
            }
        }
    }
    string str;
    str = (str + a) + (str + b) + (str + c);
    printf("Producer: %s\n", str.c_str());
   for(){
     sem_wait(&empty);
       sem_post(&full);
    }

    return 0;
}

//void *consumer(void *arg){
  //  int vowCOUNT = 0;
    //for (int place = 0; place < 3; place++){
      //  if(str[place] == 'a' | str[place] == 'e' | str[place] == 'i'| str[place] == 'o'| str[place] == 'u' ){
        //    vowCOUNT++;
        //}
   // }
//}

