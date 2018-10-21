//
//  Sample Program 2.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
//#include <mp_os.h>
#include <thread>
#include <mp_os.h>
#include <MP_THREADS>

#include "stdafx.h"
#include <POSIX>
using namespace std;

int x = 10;

//thread_create

void threadFunction1() {
    while(x > 0)
    {
    
        cout << " This is Thread 1 where, x = " << x << endl;
        x--;
    }
}

void threadFunction2(){
    
    while(x <= 10)
    {
      
        cout << "This is Thread 2 where, x = " << x << endl;
        x++;
    }
    
}


int main()
{
    
    MP_Thread t1 = new MP_Thread;
    MP_Thread t2 = new MP_Thread;
    
    t1.thread_create(threadFunction1);
    t2.thread_create(threadFunction2);
    t1.join();
    t2.join();
    return 0;
}

