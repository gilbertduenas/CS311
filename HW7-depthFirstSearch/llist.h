//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: Linked List Header file
//==============================
#ifndef LLIST_H
#define LLIST_H

typedef char el_t ;  // el_t is an alias for integer

// List node is defined here as a struct Node in order to save space. 
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};

class llist
{
 protected:
  Node *Front;  // Front  pointer 
  Node *Rear;  // Rear pointer
  int  Count;  // Counter for the number of elements
  
 public:  
  class Underflow{};  // exception handling class  
  class OutOfRange{};  // exception handling class  
  
  llist();  // constructor  
  ~llist();  // destructor
  
  // PURPOSE: check if the stack is empty 
  // HOW TO CALL: not applicable  
  bool isEmpty();
  
  // PURPOSE: display elements in linked list
  // HOW TO CALL: not applicable  
  void displayAll();
  
  // PURPOSE: add a Node to the end of the linked list
  // HOW TO CALL: pass the integer to be stored at the rear
  void addRear(el_t NewNum);
  
  // PURPOSE: delete the beginning Node of the linked list
  // HOW TO CALL: pass the integer to be deleted at the front
  void deleteFront(el_t& OldNum);
  
  // PURPOSE: add a Node to the start of the linked list
  // HOW TO CALL: pass the integer to be stored at the front
  void addFront(el_t NewNum);
  
  // PURPOSE: delete the last Node from the linked list
  // HOW TO CALL: pass the integer to be deleted at the rear
  void deleteRear(el_t& OldNum);
  
  // PURPOSE: delete the ith Node from the linked list
  // HOW TO CALL: pass the position and the integer to be deleted
  void deleteIth(int deleteIndex, el_t& OldNum);
  
  // PURPOSE: add a Node to the ith position of the linked list
  // HOW TO CALL: pass the position and the integer to be added 
  void addbeforeIth(int insertIndex, el_t newNum);

  // PURPOSE: retrieve an element from a given node
  // HOW TO CALL: pass the position of the element to be retrieved
  el_t getElement(int getIndex);
};
#endif // LLIST_H
