//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: Directed Graph Header file
//==============================
#ifndef DGRAPH_H
#define DGRAPH_H

#include <iostream>
#include <string>
#include "slist.h"
#include "stack.h"

using namespace std;

const int SIZE = 20;

//PURPOSE: This data type contains information about the vertex
//HOW TO CALL: This will be in each GTable slot
struct Gvertex
{
  char vertexName;       //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

//PURPOSE: This class creates an array of Gvertexes
//HOW TO CALL: Create an instance of this class in main
class dgraph: public slist, stack
{
 private:
   Gvertex Gtable[SIZE];
  int  countUsed; // how many slots of the Gtable are actually used
 public:
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
                      // initialize countUsed to be 0
  ~dgraph();  // Destructor, automatically calls llist destructor.
  
  void fillTable();   // read from the input file table.txt and fill GTable

  void displayGraph();  // displays in an easy to read format 

  void displayGraph2();  // displays visit information
  
  int findOutDegree(char Key);  // returns the out degree of a given vertex
	
  // returns the adjacency list of a given vertex
  slist findAdjacency(char Key);  
  
  void visit(int, char);  // enter the given visit number for a given vertex
    
  bool isMarked(char);  // return true if given vertex was already visited
};
#endif //DGRAPH_H
