//==============================
//HW3P3 copy constructor
//Gilbert Duenas
//Compiler:  g++
//File type: Implementation file
//==============================
#ifndef LLIST_CPP
#define LLIST_CPP

#include <iostream>
#include "llist.h" 
using namespace std;

// PURPOSE: Initialize Front and Rear to be NULL and Count = 0.
// The new list is empty. A Node is not created.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

// PURPOSE: If the linked list is not empty, 
// we call deleteFront repeatedly to delete all nodes.
// The user is notified as each element is deleted.
// The deleted element is passed through tempElem.
llist:: ~llist()  // Destructor
{
  el_t tempElem = 0;
  while(!isEmpty())  // Test if not isEmpty.
    {
      cout << "\nCalling the llist destructor";
      deleteFront(tempElem);
    }
  cout << endl;
} 

// PURPOSE: Test if Front and Rear are NULL. 
// ALGORITHM: Return true if Front and Rear are both pointing to NULL,
// Otherwise, return false.
bool llist::isEmpty()
{
  if((Front==NULL) && (Rear==NULL))
    return true;
  else
    return false;
}

// PURPOSE: Displays all elements from Front to Rear.
// ALGORITHM: First test if the list is empty and inform the user if so.
// Otherwise, create a temporary point and display each node. 
void llist::displayAll()
{
  if(isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      Node *tempPoint = Front;
      cout << "Displaying list.... "; 
      while(tempPoint!=NULL)  // Cycle through the list until the end.
	{
	  cout << "[" << tempPoint->Elem << "] ";  
	  tempPoint = tempPoint->Next;  // Move the pointer to the next Node.
	}
      cout << endl;
    }
}

// PURPOSE: Create a Node for the Rear of the list.
// ALGORITHM: Test if the list is empty. If so, call addFront().
// Otherwise, add a Node using the Rear Node.
void llist::addRear(el_t NewNum) 
{
  if(isEmpty())  // Test if the list is empty.
    {
      addFront(NewNum);  // Reuse of code.
      return;
    }
  Rear->Next = new Node;  // A new Node is created at Rear.
  Rear = Rear->Next;  // The Rear pointer is moved to the new Node.
  Rear->Next = NULL;  // The new Rear->Next points to the end.
  Rear->Elem = NewNum;  // The new Rear->Elem is assigned a value.
  Count++;  // The count is incremented to track the element added.
}

// PURPOSE: Remove a node from the Front of the list
// and pass the deleted value through OldNum. 
// ALGORITHM: Contains an exception handler. 
// An Underflow message will be thrown if the list is empty.
// Otherwise, the Front node will be deleted. 
void llist::deleteFront(el_t& OldNum)
{
  try  // Test for exceptions.
    {
      if(isEmpty())  // Test if the list is empty.
	{
	  throw Underflow();  // Send the error to be caught. 
	}
      else
	{
	  OldNum = Front->Elem;  // OldNum stores the deleted value for display.
	  Node *Second;  // Temporary pointer to store Front.
	  Second = Front->Next;  // Assign the pointer to the next Node to Second.
	  delete Front;
	  Count--;  // The count is decremented to track the element deleted.
	  Front = Second;  // Assign the temporary point to the Front pointer
	  if(Front==NULL)	// Test if NULL was assigned to the Front pointer.
	    {
	      Rear=NULL;  // This means the list is empty and Rear should be NULL.
	    }	
	}
    }
  catch(llist::Underflow)  // If there is an Underflow, inform the user. 
    { 
      cout << "Underflow: The list is empty." << endl;
    }
}

// PURPOSE: Create a Node at the Front of the list.
// ALGORITHM: Test if the list is empty. 
// If so, then Rear is assigned to point to Front
// after the Node is created.
void llist::addFront(el_t NewNum)
{
  bool wasEmpty = false;  // This tracks if the Node was empty.
  if(isEmpty())  // Test if the Node is empty.
    wasEmpty = true;  // If so, assign true to wasEmpty.
  Node *firstNode;  // This is a temporary Node for Front.
  firstNode = new Node;  // A new Node is created at firstNode.
  firstNode->Next = Front;  // The new Node points to the Front.
  Front = firstNode;  // The Front pointer is moved to the new Node.
  Front->Elem = NewNum;  // NewNum is assigned to the new Front Node. 
  Count++;  // Increment the counter.
  if(wasEmpty)  // Recall if the list was empty before the Node was added.
    Rear = Front;  // If so, assign the Rear pointer to the same as Front.
}

// PURPOSE: Delete a node from the Rear 
// and pass the deleted value through OldNum. 
// ALGORITHM: Test if the list is empty.
// If so, throw an exception.
// Then test if the list only has one Node. 
// Otherwise, a temporary pointer is needed to move through the list. 
void llist::deleteRear(el_t& OldNum)
{
  try  // Test for exceptions.
    {
      if(isEmpty())  // Test if the list is empty.
	{
	  throw Underflow();  // Send the error to be caught. 
	}
      else if(Front->Next==NULL)  // Test if there is 1 Node in the list
	{
	  deleteFront(OldNum);  // If so, call deleteFront().
	}
      else  
	{
	  OldNum = Rear->Elem;  // OldNum stores the deleted value for display.
	  Node *rearNode;  //  Temporary pointer to store Rear.
	  rearNode = Front;  // Set the temporary pointer at the start of the list.
	  // A while loop is used to move the pointer to the next to last pointer.
	  while(rearNode->Next!=Rear)  
	    rearNode = rearNode->Next;
	  delete Rear;
	  Count--;
	  Rear = rearNode;  // The temporary pointer is made the new Rear.
	  Rear->Next = NULL;
	}
    }
  catch(llist::Underflow)  // If there is an Underflow, inform the user. 
    { 
      cout << "Underflow: The list is empty." << endl;
    }
}

// PURPOSE: Delete a Node from a specific position deletePosition
// and pass the deleted value through OldNum.
// ALGORITHM: Must check if the list is empty 
// or if the Node to be deleted is within the list. 
// Call deleteFront or deleteRear if the position is 1 or Count.
// Otherwise, step through the list then decrement the count
// after deletion. 
void llist::deleteIth(int deletePosition, el_t& OldNum)
{
  try  // Test for exceptions.
    {
      // Test if list is empty or outside of the list 
      if(isEmpty()||deletePosition>Count||deletePosition<1)
      {
        throw OutOfRange();  // Send the error to be caught.
      }
      else if(deletePosition==1)  // Test if it is the first position.
      {
        deleteFront(OldNum);  // If so, call deleteFront().
      }
      else if(deletePosition==Count)  // Test if it is the last position.
      {
        deleteRear(OldNum);  // If so, call deleteRear().
      }
      else  // Otherwise, iterate through the list. 
      {
        Node *deleteNode;  // Temporary pointer for i-1 node before ith node
        Node *tempNode;  // Temporary pointer for i+1 node after ith node
        // Set the temporary pointer at the start of the list.
        tempNode = Front;  
        // Move through the list until just before the node to be deleted.		
        for(int k=1; k<deletePosition-1; k++)
          {
            tempNode = tempNode->Next;
          }
        deleteNode = tempNode->Next;
        OldNum = deleteNode->Elem;
        // The temporary pointer is made the new Ith node.
        tempNode->Next = deleteNode->Next;  
        delete deleteNode;
        Count--;
      }
    }
  catch (llist::OutOfRange)  // If the Node is out of range, inform the user. 
    {
      cout << "OutOfRange: Please access another node." << endl;
      OldNum = -1;
    }
}

// PURPOSE: Add a Node to a specific position insertPosition.
// ALGORITHM: Test if the position is 1 or Count+1.
// If so, call addFront() or addRear().
// A position less than 1 or greater than Count+1 is illegal.
// Otherwise, move through the list and add to the appropriate position.
void llist::addbeforeIth(int insertPosition, el_t newNum)
{
  try  // Test for exceptions. 
    {
      if(insertPosition==1)  // Check if the position is Front.
	{
	  addFront(newNum);
	}
      else if(insertPosition==Count+1)  // Check if the position is Rear.
	{
	  addRear(newNum);
	}
      // Check if the position is inside the list. 
      else if(insertPosition>Count+1||insertPosition<1)
	{
	  throw OutOfRange();
	}
      else
	{
	  Node *addNode;  // Temporary pointer for i-1 node before ith node
	  Node *tempNode;  // Temporary pointer for i+1 node after ith node
	  addNode = new Node;  // Create a new Node. 
	  tempNode = Front;  // Set the temporary pointer to the start.
	  // Move through the list until just before the position to add the new Node. 
	  for(int k=1; k<insertPosition-1; k++)
	    {
	      tempNode = tempNode->Next;
	    }
	  // Connect new Node's pointers to the following and previous Nodes.
	  addNode->Next = tempNode->Next;
	  tempNode->Next = addNode;
	  addNode->Elem = newNum;
	  Count++;
	}
    }
  catch(llist::OutOfRange)  // If the Node is out of range, inform the user. 
    {
      cout << "OutOfRange: Please access another node." << endl;
    }
}
#endif //LLIST_CPP
