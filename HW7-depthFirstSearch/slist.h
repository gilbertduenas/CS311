//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: Search List Header file
//==============================
#ifndef SLIST_H
#define SLIST_H

#include "llist.h"

// Class slist will inherit from llist publicly. This satisfies the 
// requirement that all member functions are inherited from the
// llist class. Also, slist will have access to the data members of llist,
// but the client will not access the data members.
class slist: public llist
{
 public:  
  slist();  // constructor  
  
  // copy constructor. In other words, a new linked list is created using 
  // elements from an existing list through a deep copy.
  slist(const slist& source);  
  
  // PURPOSE: Overload the assignment operator allowing a linked list
  // to have its values copied rather than just the pointers.
  // HOW TO CALL: A linked list can be assigned to another linked list
  // the way values are assigned to variables.
  // For example, destinationList = sourceList will now function 
  // the same as x=9
  slist& operator=(const slist& OtherOne);

  // PURPOSE: Overload the equality operator allowing direct comparison
  // of a linked list in size and per element.
  // HOW TO CALL: 
  bool operator==(const slist& list2) const;
  
  // PURPOSE: Searches through the list looking for Key.
  // HOW TO CALL: Pass the value you wish to locate.
  int search(el_t Key);
  
  // PURPOSE: Replace an element in the linked list
  // at a specific location.
  // HOW TO CALL: Pass an element through Elem to replace another
  // element at position I.
  void replace(el_t Elem, int I);
};
#endif //SLIST_H
