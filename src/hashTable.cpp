#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

// the maximum that can be stores int the table
const int MAX_SIZE = 30;

class HashNode
{
    public:
        int key;
        string value;
        string name;
        HashNode *next;
  
        HashNode(string name, int key, string value)
    {
        this -> name = name;
        this -> key = key;
        this -> value = value;
        this -> next = NULL;
        
    }
    
};

class HashTable
{
    public:
    
    HashNode **hTable;

    void display();
    HashTable()
            //clearing the hash table
            {
                hTable = new HashNode*[MAX_SIZE];
                
                for(int i = 0; i< MAX_SIZE; i++)
                    hTable[i] = NULL;
            }
    
    void insert(string name, int key, string value)
    {
        int hashKey = key;
        
        HashNode* prev = NULL;
        HashNode* in = hTable[hashKey];
        
        while(in != NULL)
        {
            prev = in;
            in = in -> next;
        }
        
        if(in == NULL)
        {
            in = new HashNode(name, key, value);
            
            if(prev == NULL)
            {
                hTable[hashKey] = in;
            }
            
            else
            {
                prev -> next = in;
        
            }
        }
        
        else
        {
            in -> value = value;
        }
    
        cout<< in->value <<" was inserted in key: "<< key<<endl;
        
        }

};

void HashTable:: display()
{
    HashNode *myNode;
    
    for(int i =0; i< 12; i++)
    {
        myNode = hTable[i];
        
    if(hTable[i] != NULL)
    {
         cout<<"Data at index "<< i<<" "<<endl;
    }
            while (myNode != NULL)
            {
                cout<<myNode ->name<<" ";
                cout<<myNode ->value<<endl;
                
                myNode = myNode ->next;
            }
        cout<<endl;
    }
    
    
}

// main program
int main() {
    
    string nameOfSite[50];
    string category1[15];
    char category[15];
    int sum[50];
    string value[50];
    int key[50];
    
    HashTable hash;
    
    ifstream inFile;
    inFile.open("test\\traffic.txt", ios::in);
    
    while(inFile.good())
    {
        for(int i = 0; i< 6; i++)
        {
                getline(inFile, nameOfSite[i], ',');
                getline(inFile, category1[i], ',');
                getline(inFile, value[i], '\n');
            
        }
    }
        //converting the categories to ascii values to find the key value on hash table
        for(int a = 0; a < 6 ; a++)
        {
            strcpy(category, category1[a].c_str());
            
            for(int i =0; i< 12; i++)
            {
                sum[a] += int(category[i]);
                category[i] = 0;
            }
            
            key[a] = sum[a] / 100;
    
            hash.insert(nameOfSite[a], key[a], value[a]);
        }
    
    hash.display();
    
    inFile.close();
    
    return 0;
}
