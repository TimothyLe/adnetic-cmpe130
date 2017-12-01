#include "webParse.h"
using namespace std;

void WebParse::webParser(string webname[], string adjwebname[], int webweight[]){
	int len = getFileSize();
	ifstream ifs(fileName.c_str());
	string dummyline, data;
	if(ifs.fail()){
		cout << "Error! File not found!" << endl;
		exit(1);
	}
	for(int i = 0; i < len; i++){
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

int WebParse::getFileSize(){
	int lines;
	string line;
	ifstream ifs(fileName.c_str());

	while(getline(ifs, line)) ++lines;
	return lines;
}

// WebParse::WebParse(int size, string websiteName){
//     w->weight = new int[size];
//     w->adj = new string[size];
// }

// WebParse::~WebParse(){
// 	delete [] w->weight;
// 	delete [] w->adj;
// }

// string WebParse::getWeb(){
//     return w->web;
// }

// string& WebParse::getAdj(){ //pass-by reference
//     return w->adj;
// }

// int& WebParse::getWeight(){ //pass-by reference
//     return w->weight;
// }

// ostream& operator<<(ostream& os, const WebParse& wp){
// 	os << "Website: " << wp.w->web.c_str() << " Adjacent: " << wp.w->adj.c_str() << " Weight: " << wp.w->weight;
// 	return os;
// }
// istream& operator>>(istream& is, const WebParse& wp){
// 	is >> wp.w->web;
// 	is >> wp.w->adj;
// 	is >> wp.w->weight;
// 	return is;
// }

// bool WebParse::operator==(const WebParse& wp) const{
// 	return(w->weight == wp.w->weight);

// }
// bool WebParse::operator!=(const WebParse& wp) const{
// 	return(w->weight != wp.w->weight);

// }
// bool WebParse::operator>=(const WebParse& wp) const{
// 	return(w->weight >= wp.w->weight);

// }
// bool WebParse::operator<=(const WebParse& wp) const{
// 	return(w->weight <= wp.w->weight);

// }
// bool WebParse::operator>(const WebParse& wp) const{
// 	return(w->weight > wp.w->weight);

// }
// bool WebParse::operator<(const WebParse& wp) const{
// 	return(w->weight < wp.w->weight);

// }