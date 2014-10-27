//==============================
//HW3P3 copy constructor
//Gilbert Duenas
//Compiler:  g++
//File type: main cpp file
//==============================
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include "slist.h"
using namespace std;

void CopyTest(slist list, int input);  // CopyTest function prototype

int main()
{
  int result = 0;  // A variable to store search results.
  slist L1;  // Declare a list for the first test case list.
  slist L2;  // Declare a list for the second test case list.

  //1.	Create a 5 element list with  1,2,3,4,5 (L1)
  cout << "//1.	Create a 5 element list with  1,2,3,4,5 (L1)" << endl;
  L1.addRear(1);
  L1.addRear(2);
  L1.addRear(3);
  L1.addRear(4);
  L1.addRear(5);
  
  //2.	Pass the list to a client function called CopyTest 
    //to test your copy constructor.
  //a.	Copytest will receive the list passed by value from main() and
  //b.	Simply 
    //1) add a node to its rear with 6 in it (should not affect the original)
    //2) display it (6 elements 1,2,3,4,5,6)
  cout << "//2.	Pass the list to a client function called CopyTest" << endl;
  CopyTest(L1, 6);
  
  //3.	Display L1 	(this should still be a 5 element list)
  cout << "//3.	Display L1 	(this should still be a 5 element list)" << endl;
  L1.displayAll();
  
  //4.	Do L1 = L1;
  cout << "//4.	Do L1 = L1;" << endl;
  L1 = L1;
  
  //5.	Display L1    	(this should still be 1 2 3 4 5)
  cout << "//5.	Display L1    	(this should still be 1 2 3 4 5)" << endl;
  L1.displayAll();
  
  //6.	Create a 4 element list L2 with 7,8,9,10.
  cout << "//6.	Create a 4 element list L2 with 7,8,9,10." << endl;
  L2.addRear(7);
  L2.addRear(8);
  L2.addRear(9);
  L2.addRear(10);
  
  //7.	Display L2
  cout << "//7.	Display L2" << endl;
  L2.displayAll();
  
  //8.	Do L2 = L1;  	(L2 becomes 5 elements 1,2,3,4,5)
  cout << "//8.	Do L2 = L1;  	(L2 becomes 5 elements 1,2,3,4,5)" << endl;
  L2 = L1;
  
  //9.	Display L2.
  cout << "//9.	Display L2." << endl;
  L2.displayAll();
  
  //10.	Remove a rear node from L1. (This should not affect L2).
  cout << "//10.	Remove a rear node from L1.";
  cout << "(This should not affect L2)." << endl;
  L1.deleteRear(result);
  
  //11.	Display L1.   	(L1 is 1,2,3,4)
  cout << "//11.	Display L1.   	(L1 is 1,2,3,4)" << endl;
  L1.displayAll();
  
  //12.	Display L1 again. (4 elements)
  cout << "//12.	Display L1 again. (4 elements)" << endl;
  L1.displayAll();
  
  //13.	Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << "//13.	Display L2 again. (still 5 elements 1,2,3,4,5)" << endl;
  L2.displayAll();
  
  return 0;
}

// PURPOSE: CopyTest function definition. Pass the list to be copied and 
// the variable to be added to the rear.
void CopyTest(slist list, int input)
{
  // Create a temporary and local list using the copy constructor
  slist testList(list);  
  testList.addRear(input);
  cout << "Display all from CopyTest function" << endl;
  testList.displayAll();  // Show the new list with the variable at the end
}
#endif //MAIN_CPP
