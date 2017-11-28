#include "webFile.h"
using namespace std;


WebFile::WebFile(string filePath, int len){
	WebParse wp; 
	int webweight;
	ifstream wFile;
	string dummy, data;
	wFile.open(filePath.c_str());
	if(wFile.fail()){
		cout << "Error! File does not found\n";
		exit(1);
	}
	getline(wFile, dummy);
	while(!wFile.eof()){
		for(int i = 0; i < len; i++){
			getline(wFile, wp.web, ',');
			getline(wFile, wp.adj[i], ',');
			getline(wFile, wp.weight[i], ',');
			data = data.substr(0, data.find(','));
			if(isdigit(data[])){
                istringstream iss(data);
                int weight;
                while(iss >> wp.weight){
                    wp.weight[i]=webweight;
                }
        	}
		}
	}
	wFile.close();
}	
WebParse WebFile::getWebsites(){
	return webs.at(0);
}
list<WebParse> WebFile::getAdjacents(){
	list<WebParse> toReturn;

	return toReturn;
}
list<WebParse> WebFile::getWeights(){
	list<WebParse> toReturn;

	return toReturn;
}