// Implementation file for driver program of Hash, Dag, and parser

#include "DAG.h"
#include "webParse.h"
using namespace std;

int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    string fName = "test\\adsAPISM.dat";
    WebParse(fName);
    Graph g(6);
    for(int i = 0; i< 10; i++){
        int count_web, count_adj,count;
        count_web = ShuffleDAG(webname[i], count_web);
        cout << webname[i] << " " << count_web << " ";
        count_adj = ShuffleDAG(adjwebname[i], count_adj);
        count=webweight[i];
        cout << adjwebname[i] << " " << count_adj << "\ncount\n";
    
       g.addEdge(count_web, count_adj,count);
    }
    int k = 0;
    cout << "Following are longest distances from source vertex"<<endl;
    g.longestPath(k,webname);
    return 0;
    }
    

/*ifd.open("adsAPISM2.dat");
    if(ifd.fail()){
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    for(int i=0; i<1; i++){
        getline(ifd, dummyline);
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
            int i, count_web2, count_adj2,count2 = 0;
            Graph g(6);
            for(i = 0; i< 11; i++){
 
                
                if(webname2[i]=="StartingPoint2") count_web2= 0;
                else if(webname2[i]=="Snapchat")count_web2=arr[0];
                else if(webname2[i]=="Twitter")count_web2=arr[1];
                else if(webname2[i]=="Instagram")count_web2=arr[2];
                else if(webname2[i]=="WhatsApp")count_web2=arr[3];
                else count_web2=arr[4];
                
                cout<< count_web2;
                
                
                if(adjwebname2[i]=="StartingPoint2") count_adj2 = 0;
                else if(adjwebname2[i]=="Snapchat")count_adj2=arr[0];
                else if(adjwebname2[i]=="Twitter")count_adj2=arr[1];
                else if(adjwebname2[i]=="Instagram")count_adj2=arr[2];
                else if(adjwebname2[i]=="WhatsApp")count_adj2=arr[3];
                else count_adj2=arr[4];
                cout<<" its adj is "<<count_adj2<<endl;
                
                
                count2=webweight2[i];
                
                //cout<<count<<endl;
                
                g.addEdge(count_web2, count_adj2,count2);
            }
        
        
            cout << "Following are longest distances from source vertex"<<endl;
        g.longestPath(0,webname);
        return 0;
}
}
*/