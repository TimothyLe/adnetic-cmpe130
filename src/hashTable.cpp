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
    string findMax(string);
    
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

int find_key(string k)
{
    char copy[50];
    int key;
    int sum=0;
    int length = k.length();
    
    strcpy(copy, k.c_str());
    
    
    for(int i =0; i<length; i++)
    {
              sum += int(copy[i]);
        
    }
    
    key = sum / 100;
    
    return key;
}

string HashTable:: findMax(string categoryIn)
{
    HashNode *list = NULL;
    HashNode *ptr = NULL;
    string max;
    string max_name;
    
    int key = find_key(categoryIn);
    
    for(int i = 0; i< 20; i++)
    {
        list = hTable[key];
    }
    
    max = list->value;
    max_name = list->name;
    
    if(list!=NULL)
    {
        if(list->next != NULL)
        {
            ptr = list ->next;
            
                if(ptr->value > max)
                {
                    max = ptr->value;
                    max_name = ptr -> name;
                }
                
                else
                    while(ptr->next != NULL)
                    {
                        ptr = ptr ->next;
                    }
            }
        }
    

    return max_name;
}

// main program
int main() {
    
    string nameOfSite[50];
    string category1[15];
    string value[50];
    string max;
    char category[15];
    int sum[50];
    int key[50];
    int length;
    
    HashTable hash;
    
    ifstream inFile;
    inFile.open("traffic.txt");
    
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
            length = category1[a].length();
            
            for(int i =0; i< length; i++)
            {
                sum[a] += int(category[i]);
                category[i] = 0;
            }
            
            key[a] = sum[a] / 100;
    
            hash.insert(nameOfSite[a], key[a], value[a]);
        }
    
    hash.display();
    
    max = hash.findMax(category1[3]);
    
    cout<<"The most Valuable of " <<category1[3]<<" is "<< max<<endl;
    
    inFile.close();
    
    return 0;
}
