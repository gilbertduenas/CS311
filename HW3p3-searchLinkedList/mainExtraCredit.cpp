//==============================
//HW3P3 overload equality operator Extra Credit
//Gilbert Duenas
//Compiler:  g++
//File type: main cpp file
//==============================
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include "slist.h"
using namespace std;

// Compare list prototype. Note lists are passed by reference
void CompareTest(slist& list1, slist& list2);

int main()
{
  int result = 0;  // A variable to store search results.
  slist L1;  // Declare a list for the first test case list.
  slist L2;  // Declare a list for the second test case list.

  //1.	L1 is empty and L2 is empty
  cout << "\n//1. L1 is empty and L2 is empty";
  CompareTest(L1, L2);

  //2.	L1 is empty and L2 has 2 elements
  cout << "\n//Adding 2 elements to L2";
  L2.addRear(1);
  L2.addRear(2);
  cout << "\n//2. L1 is empty and L2 has 2 elements";
  CompareTest(L1, L2);

  //3.	L1 has 2 elements and L2 is empty
  cout << "\n//Adding 2 elements to L1 and deleting 2 elements from L2";
  L1.addRear(1);
  L1.addRear(2);
  L2.deleteRear(result);
  L2.deleteRear(result);
  cout << "\n//3. L1 has 2 elements and L2 is empty";
  CompareTest(L1, L2);

  //4.	L1 has 1,2,3 and L2 has 1,2,3
  cout << "\n//Adding 1 element to L1 and adding 3 elements to L2";
  L1.addRear(3);
  L2.addRear(1);
  L2.addRear(2);
  L2.addRear(3);
  cout << "\n//4. L1 has 1,2,3 and L2 has 1,2,3";
  CompareTest(L1, L2);

  //5.	L1 has 1,2,3 and L2 has 1,2
  cout << "\n//Deleting 1 element from L2";
  L2.deleteRear(result);
  cout << "\n//5. L1 has 1,2,3 and L2 has 1,2";
  CompareTest(L1, L2);

  //6.	L1 has 1,2,3 and L2 has 1,2,3,4
  cout << "\n//Adding 2 elements to L2";
  L2.addRear(3);
  L2.addRear(4);
  cout << "\n//6. L1 has 1,2,3 and L2 has 1,2,3,4";
  CompareTest(L1, L2);

  //7.	L1 has 1,2,3 and L2 has 1,2,4
  cout << "\n//Deleting 3rd element from L2";
  L2.deleteIth(3, result);
  cout << "\n//7. L1 has 1,2,3 and L2 has 1,2,4";
  CompareTest(L1, L2);

  return 0;
}

// PURPOSE: Compare the elements of two lists and inform the user of the result
void CompareTest(slist& list1, slist& list2)
{
  cout << "\nL1: "; 
  list1.displayAll(); 
  cout << " & L2: "; 
  list2.displayAll();
  cout << "Comparing lists.... ";
  // Overloading the equality operator makes this possible.
  // A 'no match' error is returned if the operator is not overloaded
  if(list1==list2)
  {
    cout << "Equivalent" << endl;
  }
  else
  {
    cout << "Not Equivalent" << endl;
    }
}
#endif //MAIN_CPP
