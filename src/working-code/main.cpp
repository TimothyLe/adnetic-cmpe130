// A C++ program to find single source longest distances in a DAG
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <list>
#include <stack>
#include <limits.h>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdio>

#include "Hash.h"
#include "Graph.hpp"

#define NINF INT_MIN

using namespace std;

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

int ShuffleDAG(string array){
    int i=0;
    int count;
    int arr[5];
    for (i=0; i<5; i++){
        arr[i] = i+1;
    }
    
    shuffle(arr, 5);
    
    if (strcmp(array.c_str(),"StartingPoint")==0)
        count= 0;
    else if(strcmp(array.c_str(),"Snapchat")==0)
        count=arr[0];
    else if(strcmp(array.c_str(),"Twitter")==0)
        count=arr[1];
    else if(strcmp(array.c_str(),"Instagram")==0)
        count=arr[2];
    else if(strcmp(array.c_str(),"WhatsApp")==0)
        count=arr[3];
    else count=arr[4];
    
    return count;
}


// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    
    int webweight[50], webweight2[50], sum[50], key[50], val[50];
    int count_web[10], count_adj[10],count_web2[10], count_adj2[10], length,v, maxVertex[2];
    string webname[50],webname2[50], adjwebname[50],adjwebname2[50], nameOfSite[50], category1[15];
    string value, maxAd, categ, data;
    char category[15];
    
    HashTable hash;
    ifstream ifs,ifd, inFile;
    
    inFile.open("traffic.txt");
    
    if(inFile.fail())
    {
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    
    while(inFile.good())
    {
        for(int i = 0; i< 15; i++)
        {
            getline(inFile, nameOfSite[i], ',');
            getline(inFile, category1[i], ',');
            getline(inFile, value, '\n');
            
            
            istringstream iss(value);
            
            while(iss >> v)
            {
                val[i] = v;
            }
        }
    }
    
    cout<<"--------------Hash Table-------------"<<endl;
    cout<<endl;
    
    //converting the categories to ascii values to find the key value on hash table
    for(int a = 0; a < 13 ; a++)
    {
        strcpy(category, category1[a].c_str());
        length = category1[a].length();
        
        for(int i =0; i< length; i++)
        {
            sum[a] += int(category[i]);
            category[i] = 0;
        }
        
        key[a] = sum[a] / 100;
        
        hash.insert(nameOfSite[a], key[a], val[a]);
    }
    
    cout<<endl;
    
    inFile.close();
    
    ifs.open("adsAPISM.dat");
    
    if(ifs.fail())
    {
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++)
    {
        getline(ifs, categ);
    }
    
        for(int i = 0; i<11; i++)
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


        Graph g(6);
    cout<<"-------adsAPISM File:------ "<<endl;
    cout<<"Webname---Webvertex----adjacentWeb---adjVertex"<<endl;
    cout<<endl;
            for(int i = 0; i< 11; i++)
            {
                count_web[i] = ShuffleDAG(webname[i]);
                count_adj[i] = ShuffleDAG(adjwebname[i]);
         
                cout<<webname[i]<<" "<<count_web[i]<<" "<<adjwebname[i]<<" "<<count_adj[i]<<endl;
        
                g.addEdge(count_web[i], count_adj[i], webweight[i]);

            }
        
            maxVertex[0] = g.longestPath(0,webname);
    
    ifd.open("adsAPISM2.dat");
    if(ifd.fail()){
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++){
        getline(ifd, categ);
    }
    while(!ifd.eof()){
        
        for(int i = 0; i< 15; i++)
        {
            getline(ifd, webname2[i], ',');
            getline(ifd, adjwebname2[i], ',');
            getline(ifd, data);
            data = data.substr(0, data.find(','));
            if(isdigit(data[0])){
                istringstream iss(data);
                int weight;
                while(iss >> weight){
                    webweight2[i]=weight;}
            }
        }
        
        cout<<"-------adsAPISM2 File:-------"<<endl;
        cout<<"Webname---Webvertex----adjacentWeb---adjVertex"<<endl;
        cout<<endl;
        Graph g(6);
        for(int i = 0; i< 11; i++)
        {
            count_web2[i]= ShuffleDAG(webname2[i]);
            count_adj2[i]= ShuffleDAG(adjwebname2[i]);
            
            cout<<webname2[i]<<" "<<count_web2[i]<<" "<<adjwebname2[i]<<" "<<count_adj2[i]<<endl;
            
            g.addEdge(count_web2[i], count_adj2[i],webweight2[i]);
        }
        
        int s=0;
        
        maxVertex[1] = g.longestPath(s,webname2);
        
        maxAd = hash.findMax(categ);
        
        cout<<endl;
        cout<<"The final output:"<<endl;
        cout<<"Ad "<<maxAd<<" will be displayed on";
        
        for(int i=0; i< 11; i++)
        {
            if(maxVertex[0]>maxVertex[1])
            {
                if(count_web[i]  == maxVertex[0])
                {
                    cout<<" "<<webname[i];
                    cout<<" from file adsAPISM.dat"<<endl;
                    break;
                }
                else
                    if(count_adj[i] == maxVertex[0])
                    {
                        cout<< " "<<adjwebname[i];
                        cout<<" from file adsAPISM.dat"<<endl;
                        break;
                    }
                
            }
            else if(maxVertex[1]>maxVertex[0])
            {
                if(count_web2[i]  == maxVertex[1])
                {
                    cout<<" "<<webname2[i];
                    cout<<" from file adsAPISM.dat"<<endl;
                    break;
                }
                else
                    if(count_adj2[i] == maxVertex[1])
                    {
                        cout<< " "<<adjwebname2[i];
                        cout<<" from file adsAPISM.dat"<<endl;
                        break;
                    }
            
            }

        }
        
        cout<<endl;
        return 0;
    }
}




