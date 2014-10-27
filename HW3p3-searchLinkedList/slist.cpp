//==============================
//HW3P3 copy constructor
//Gilbert Duenas
//Compiler:  g++
//File type: Implementation file
//==============================
#ifndef SLIST_CPP
#define SLIST_CPP

#include <iostream>
#include "slist.h" 
using namespace std;

// PURPOSE: Initialize Front and Rear to be NULL and Count = 0.
// The new list is empty. A Node is not created. This basically calls the 
// llist constructor.
slist::slist(){}

// PURPOSE: Similar to the preceding constructor. This second constructor
// creates a linked list that is populated with elements from an existing 
// linked list. 
slist::slist(const slist& source)
{
  el_t temp = 0;
  if (&source != this)  // if not the same then procede
  {
    // this-> object has to be emptied first.
    while(! this->isEmpty() )
    {
      this->deleteRear(temp);
    }
    // this-> object has to be built up by allocating new cells (**)
    Node* P;  // local pointer for the source linked list
    P = source.Front;
    // This uses a loop which repeats until the end of the source linked list
    while (P != NULL)  
    {
      this->addRear(P->Elem);  //P’s element is added to this->
      P = P->Next;  // Go to the next node in source linked list   
    } 
  }// end of if
}

// PURPOSE: Overload the assignment operator to allow elements from one
// linked list to be copied into another linked list. This is a deep copy. 
// Without overloading, only the pointer is copied, which is a shallow copy.
slist& slist::operator=(const slist& OtherOne)
{
  el_t temp = 0;
  // First make sure this-> and OtherOne are not the same object. 
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
  {
    // this-> object has to be emptied first.
    while(! this->isEmpty())
    {
      this->deleteRear(temp);
    }
    // this-> object has to be built up by allocating new cells (**)
    Node* P;  // local pointer for OtherOne
    P = OtherOne.Front;
    // This uses a loop which repeats until you reach the end of OtherOne. 
    while (P != NULL)  
    {
      this->addRear(P->Elem);  //P’s element is added to this->
      P = P->Next;  // Go to the next node in OtherOne   
    } 
  }// end of if              
  return *this;  // return the result unconditionally.
}

// PURPOSE: Overload the equality operator to allow direct comparison 
// of linked lists.
bool slist::operator==(const slist& list2) const
{
  // Check if the lists are the same size
  if(this->Count != list2.Count)
  {
    return false;
  }
  Node* P1;  // local pointer for listTest
  Node* P2;
  P1 = this->Front;
  P2 = list2.Front;
  while (P1!= NULL)  // This uses a loop which repeats until you reach the end of listTest. 
  {
    if (P1->Elem!=P2->Elem)  // Check if the elements are not equal
    {
      return false;
    }  
  // Advance to the next set of nodes in both linked lists
  P1 = P1->Next;
  P2 = P2->Next;
  } 
  // True will be returned if all the elements are the same  
  return true; 
}

// PURPOSE: Find a element and return its position or return 0.
// ALGORITHM: Test if the list is empty, then move through the list.
// Return the element's position (not the element) if it is found.
// Otherwise, inform the user and return 0.
int slist::search(el_t Key)
{
  int position = 1;  // Declare a variable to track the position.
  if(isEmpty())  // Test if the list is empty.
    cout << "[ empty ]" << endl;
  else
    {
      // Use a temporary point to cycle through the list.
      Node *tempPoint = this->Front;  
      while(tempPoint!=NULL)  // Cycle through the list until the end.
      {
        if(tempPoint->Elem==Key)  // Check if Key matches the current element.
          {
            cout << Key << " found at position " << position << endl;
            return position;
          }
        position++;  // Increment the position.
        tempPoint = tempPoint->Next;  // Move the pointer to the next Node.
      }
      // At this point, the element was not found so return 0. 
      cout << Key << " not found. " << endl;
      return 0;
    }
}

// PURPOSE: Replace an existing element with another at a specific location.
// ALGORITHM: Pass the new element and the location it will replace.
void slist::replace(el_t Elem, int I)
{
  el_t temp = 0;  // Declare a placeholder for the deleteIth function.
  deleteIth(I, temp);  // We can simply call the deleteIth function.
  if(temp!=-1)
    {
      // Inform the user of the process taking place.
      cout << "Replacing " <<  temp << " with " << Elem << " at position " << I << endl;
      addbeforeIth(I, Elem);  // And the addbeforeIth function. 
    }
}
#endif //SLIST_CPP
