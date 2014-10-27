//==============================
//HW1P1 queue
//Gilbert Duenas
//Compiler:  g++
//File type: Client file
//==============================
#ifndef CLIENT2_CPP
#define CLIENT2_CPP

#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

// Purpose of the program: Demonstrate a queue data structure using
// a static array. The program will cycle through two while loops.
// Compile client2.cpp queue.h and queue.cpp together. Run the program.
int main()
{
  string frontElement;
  string frontElement2;  // place holders for the front element
  queue stringQueue;     // create an instance of queue
  queue stringQueue2;    // create a second instance of queue
  
  // This loop will display the front element, the indexes for front and rear,
  // the array element count, and the values inside the array for each pass.
  cout << "\nFIRST RUN" << endl;
  stringQueue.displayAll();
  while(stringQueue.getSize()<25)  // loop until the array size exceeds 25
    {
      stringQueue.frontElem(frontElement);
      stringQueue.add("A");
      stringQueue.add("B");
      stringQueue.add("C");
      stringQueue.remove(frontElement);
      stringQueue.displayAll();
    }	
  
  // This loop will run until the array is full. 
  // It will only display the front element.
  cout << "\nSECOND RUN" << endl;
  while(true)  // loop infinitely
    {
      stringQueue2.frontElem(frontElement2);
      stringQueue2.add("A");
      stringQueue2.add("B");
      stringQueue2.add("C");
      stringQueue2.remove(frontElement2);
    }	

  return 0;
}
#endif //CLIENT2_CPP
