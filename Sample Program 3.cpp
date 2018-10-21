//
//  Sample Program 3.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sys/types.h>
//#include <mp_os.h>
#include <thread>
#include <mp_os.h>
#include <MP_THREADS>

#include "stdafx.h"
#include <POSIX>
#include <pthread.h>

/*In this program, there is a common resource between the threads and thread 1 must initialize it before the other can use it, but if the one that tried to initializ it doesnt run yet then the other thread should crash*/


using namespace std;
int x;

void threadFunction1(int x){
    x = 100;  //initialize x inside of thread 1
    cout << "thread 1 executing, x =  " << x << endl;
 
}

void threadFunction2(int x){
    x = x + 1;  //should crash if thread 1 hasn't initialized x
    cout << "thread 2 is executing, x =  " << x << endl;
}

int main(){
        
    MP_Thread t1 = new MP_Thread;
    MP_Thread t2 = new MP_Thread;

    t1.thread_create(threadFunction1);
    t2.thread_create(threadFunction2);


    t1.join();
    t2.join();
    
    return(0);
}

