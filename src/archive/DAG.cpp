// Definition file for DAG header
#include "DAG.h"
using namespace std;

Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}


// A recursive function used by longestPath
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
    
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

// The function to find longest distances from a given vertex. It uses
// recursive topologicalSortUtil() to get topological sorting.
void Graph::longestPath(int s, string obj[])
{
    stack<int> Stack;
    int dist[V];
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
    
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topologicaxl order
        int u = Stack.top();
        Stack.pop();
        
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (dist[i->getV()] < dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
    
    // Print the calculated longest distances
    for (int i = 0; i < V; i++)
        (dist[i] == NINF)? cout << "INF ": cout << dist[i] << " "<<endl;
}

// Montonic sequence shuffling helper function
void Graph::shuffle(int *arr, size_t n)
{
    srand( static_cast<unsigned int>(time(NULL)));
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

// Shuffling application to the DAG array
int Graph::ShuffleDAG(string array, int count){
    int i=0;
    int arr[5];
    for (i=0; i<5; i++){
        arr[i] = i+1;
    }
    shuffle(arr, 5);
    if (strcmp(array.c_str(),"StartingPoint"))count= 0;
    else if(strcmp(array.c_str(),"Snapchat"))count=arr[0];
    else if(strcmp(array.c_str(),"Twitter"))count=arr[1];
    else if(strcmp(array.c_str(),"Instagram"))count=arr[2];
    else if(strcmp(array.c_str(),"WhatsApp"))count=arr[3];
    else count=arr[4];
    return count;
}
