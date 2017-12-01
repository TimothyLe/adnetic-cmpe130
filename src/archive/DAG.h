#ifndef _DAG_
#define _DAG_

//program to find single source longest distances in a DAG
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <list>
#include <stack>
#include <limits.h>
#include <ctime>
#define NINF INT_MIN
using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
    
};

class Graph
{
    int V;    // No. of vertices'
    
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
    
    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
    int count = 0;
    
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    
    // Finds longest distances from given source vertex
    void longestPath(int s, string obj[]);

    // Montonic sequence shuffling helper function
    void shuffle(int *arr, size_t n);

    // Shuffling application to the DAG array
	int ShuffleDAG(string array, int count);
};

#endif //_DAG_