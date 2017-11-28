#include "webFile.h"
using namespace std;

WebFile::WebFile(string filePath){
	ifstream wFile(filePath);
	string data;
	if(wFile.fail()){
		cout << "Error! File does not found\n";
		return -1;
	}
	while(!wFile.eof()){

	}
	wFile.close();
	sort(students.begin(), students.end(), [](Student &s1, Student &s2)
    										{
                                                return s1.getGPA() > s2.getGPA();
                                            });
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