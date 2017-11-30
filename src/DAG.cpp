// A C++ program to find single source longest distances in a DAG
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <stack>
#include <limits.h>
#include <ctime>
#define NINF INT_MIN
using namespace std;
// Graph is represented using adjacency list. Every node of adjacency list
// contains vertex number of the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
    
};

// Class to represent a graph using adjacency list representation
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
    
};

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


// A recursive function used by longestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
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
        // Get the next vertex from topological order
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
        (dist[i] == NINF)? cout << "INF ": cout << dist[i] << " ";
}
void shuffle(int *arr, size_t n)
{
    if (n > 1)
    {
        size_t i;
        srand( static_cast<unsigned int>(time(NULL)));
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    int i=0;
    int arr[5];
    for (i=0; i<5; i++){
        arr[i] = i+1;
    }
    shuffle(arr, 5);
    for (i=0; i<5; i++){
        cout<<arr[i]<<endl;
    }
    int webweight[10];
    string webname[10];
    string adjwebname[10];
    ifstream ifs;
    ifs.open("test\\adsAPI.dat");
    string dummyline,data;
    if(ifs.fail()){
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++){
        getline(ifs, dummyline);
    }
    while(!ifs.eof()){
        
        for(int i = 0; i< 10; i++)
        {
            getline(ifs, webname[i], ',');
            getline(ifs, adjwebname[i], ',');
            getline(ifs, data);
            data = data.substr(0, data.find(','));
            if(isdigit(data[0])){
                istringstream iss(data);
                int weight;
                while(iss >> weight){
                    webweight[i]=weight;}
        }
       }
        int i, count_web, count_adj,count = 0;
        Graph g(6);
        for(i = 0; i< 10; i++){
        /*cout<<webname[i]<<endl;
        cout<<adjwebname[i]<<endl;
        cout<<webweight[i]<<endl;*/
            
            if(webname[i]=="Facebook") count_web = 0;
            else if(webname[i]=="Snapchat")count_web=arr[0];
            else if(webname[i]=="Twitter")count_web=arr[1];
            else if(webname[i]=="Instagram")count_web=arr[2];
            else if(webname[i]=="WhatsApp")count_web=arr[3];
            else count_web=arr[4];
            cout<< count_web;
            
            
            if(adjwebname[i]=="Facebook") count_adj = 0;
            else if(adjwebname[i]=="Snapchat")count_adj=arr[0];
            else if(adjwebname[i]=="Twitter")count_adj=arr[1];
            else if(adjwebname[i]=="Instagram")count_adj=arr[2];
            else if(adjwebname[i]=="WhatsApp")count_adj=arr[3];
            else count_adj=arr[4];
            cout<<" its adj is "<<count_adj<<endl;
      
            
            count=webweight[i];

           //cout<<count<<endl;
            
        g.addEdge(count_web, count_adj,count);
        }
        int s = 0;
        cout << "Following are longest distances from source vertex " << s <<" \n";
        g.longestPath(s,webname);
         return 0;
}
}
  