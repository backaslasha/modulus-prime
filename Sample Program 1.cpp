//
//  main.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <mp_os.h>
#include <MP_THREADS>
#include <thread>
#include "stdafx.h"
using namespace std;


//This program will crash because we do not join thread t1 to the main thread before main terminates

void threadFunction1() {
    cout << "Inside thread function 1 " << endl;
    
}


int main()
{
    
    MP_Thread t1 = new MP_Thread;
  
    t1.thread_create(threadFunction1);
    
    return 0;
}
