//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: Directed Graph Implementation file
//==============================
#ifndef DGRAPH_CPP
#define DGRAPH_CPP

#include <iostream>
#include <fstream>
#include "dgraph.h"
using namespace std;

// Constructor
dgraph::dgraph()
{
  for(int i = 0; i<SIZE; i++)
  {
    // Values for Gvertex elements are initialized as requested
    Gtable[i].vertexName = ' ';  //the vertex Name (blank)
    Gtable[i].outDegree = 0; 	//the Out degree (0)
    Gtable[i].visit = 0;  // This variable is used for the next assignment.
  }
  countUsed = 0; // Tracks the number of arrays used.
} 

// Destructor: llist destructor is called automatically
dgraph::~dgraph(){}   

// Reads a file and enters information into the table 
void dgraph::fillTable()
{
  ifstream fin ("table.txt", ios::in);
  char x; 
  int count;
  int index = 0;
  while (fin >> x)  // The file is read until the end
  { 
    cout << "Got " << x << " and " << endl;
    // The first data is stored as the vertexName
    Gtable[index].vertexName = x; 
    fin >> count;
    // Then the out Degree
    Gtable[index].outDegree = count;
    countUsed++;  
    // The out Degree determines how many items 
    // are added to Gtable's linked list
    for (int i = 1; i <= count; i++) 
    {
      fin >> x;
      cout << "\tgot " << x << " ";
      (Gtable[index].adjacentOnes).addRear(x);
    }
    cout << endl;
    index++;
  }
  fin.close();
}

// This displays the data entered into the graph
void dgraph::displayGraph()
{
  for (int i = 0; i < countUsed; i++)
  {
    cout << "Vertex Name: " << Gtable[i].vertexName; 
    cout << "\tOut Degree: " << Gtable[i].outDegree << endl;
    (Gtable[i].adjacentOnes).displayAll();
  }  
}  // displays in an easy to read format 

// This displays the visit information of graph
void dgraph::displayGraph2()
{
  for(int i = 1; i <= countUsed; i++)
  {
    for(int j = 0; j < countUsed; j++)
    {
      if(Gtable[j].visit==i)
      {
        cout << "Vertex Name: " << Gtable[j].vertexName;
        cout << "\t\tVisit Number: " << Gtable[j].visit << endl;
      }
    }
  }
}  // displays in an easy to read format 

// This function searches for the out degree of a vertex
// with a for loop. A character is passed, but an integer is returned.
int dgraph::findOutDegree(char Key)
{
  for(int i = 0; i < countUsed; i++)
  {
    if(Key == Gtable[i].vertexName)
    {
      return Gtable[i].outDegree;
    }
  }
  cout << Key << " not found." << endl;
  return 0;
}  

// This function determines what is adjacent to a vertex	
// with a for loop. A character is passed, but a linked list is returned.
slist dgraph::findAdjacency(char Key)
{
  for(int i = 0; i<countUsed; i++)
  {
    if(Key == Gtable[i].vertexName)
    {
      return Gtable[i].adjacentOnes;
    }
  }
  cout << Key << " not found." << endl;
  slist empty;
  return empty;
}  

// This function assigns a visit number to a given element. 
void dgraph::visit(int elem, char Key)
{
  for(int i=0; i< countUsed; i++)
  {
    if(Gtable[i].vertexName == Key) // Check if the Key matches the Name
    {
      Gtable[i].visit = elem; // Assign a value to visit
    }
  }
}
  
// This function returns true if vertex passed was already visited  
bool dgraph::isMarked(char Key)
{
  for(int i = 0; i < countUsed; i++)
  {
    if(Key == Gtable[i].vertexName) // Check if the Key matches the Name
    {
      if(Gtable[i].visit != 0) // Check if a value for visit exists
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  cout << Key << " not found." << endl;
} 
#endif //DGRAPH_CPP
