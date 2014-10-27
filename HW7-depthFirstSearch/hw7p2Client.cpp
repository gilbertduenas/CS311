//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: Client file
//==============================
#ifndef HW7P2CLIENT_CPP
#define HW7P2CLIENT_CPP

#include <iostream>
using namespace std;
#include "dgraph.h"

void checkVisit(dgraph& dg1, stack& vtx1, char vertexData, int& visitMark);

void checkAdjacent(dgraph& dg1, stack& vtx1, char vertexData);

int main()
{
  char vertex1;  // Receive characters from pop
  int visitMark = 1;  // Track the visit order number
  
  dgraph dg1;  // Primary array to store tree information
  stack vtx1;  // This is needed to store vertexes in a stack
  
  // Calling fillTable()
 cout << "Filling table.... " << endl; 
  dg1.fillTable();

  // Calling displayGraph() before DFS begins. 
  cout << "\nDisplaying graph before DFS begins...." << endl;
  dg1.displayGraph();
  
  cout << "\n\nBegin DFS with A...." << endl;
  // Mark/visit A (**), the start vertex visit number as 1 
  checkVisit(dg1, vtx1, 'A', visitMark);

  // This while loops handles the rest of the elements in the graph
  // by popping the top element from the stack and checking for 
  // its adjacencies
  while(!vtx1.isEmpty())
  {
    vtx1.pop(vertex1);  //	Remove a vertex v from the stack.
    cout << "\nPop " << vertex1;  // Display the vertex name.
    // If vertex1 is not marked yet (visit number is 0) then 
    checkVisit(dg1, vtx1, vertex1, visitMark);
  }
  
  // Display the Graph with visit numbers for all vertices.
  cout << "\n\nDisplaying graph for all vertices by order of visit..." << endl;
  dg1.displayGraph2();
  
  cout << "\nThanks! It's been a great semester." << endl;
  return 0;
}

// This function condenses the check for whether a vertex has been visited.
// It requires the graph, the stack, the vertex, and visit number to be passed.
// The graph, stack, and visit number are passed by reference.
void checkVisit(dgraph& dg1, stack& vtx1, char vertexData, int& visitMark)
{
  if(!dg1.isMarked(vertexData))
  {
    dg1.visit(visitMark, vertexData);
    cout << ".... first visit, adding mark" << endl;
    visitMark++;
    // Test if the vertex has any adjacencies
    checkAdjacent(dg1, vtx1, vertexData);
  }
  else
  {
    cout << ".... already visited" << endl;
  }
}

// This function condenses the check for whether a vertex has adjacencies
// It requires the graph, the stack, and vertex to be passed.
// The graph and stack are passed by reference.
void checkAdjacent(dgraph& dg1, stack& vtx1, char vertexData)
{
  // Variable to store value from findOutDegree()
  int outDegree = 0;
  // This is needed to store the adjacency list from findAdjacency() 
  slist slData = dg1.findAdjacency(vertexData); 
  // Check if adjacency list is empty. If not, then push list onto stack.
  if(!slData.isEmpty())
  {
    outDegree = dg1.findOutDegree(vertexData)-1; // Determine the start index
    cout << "Pushing " << vertexData << "'s list onto stack...." << endl;
    // This while loop starts at the last element of the linked list...
    while(outDegree>=0)
    {
      // then pushes into the stack and proceeds to the first element
      vtx1.push(slData.getElement(outDegree)); 
      outDegree--;
    }
    cout << "\nSTACK after " << vertexData << endl; //Display the updated stack
    vtx1.displayAll();
  }
  else
  {
    cout << "No adjacent vertices...." << endl;
  }
}
#endif //HW7P2CLIENT_CPP
