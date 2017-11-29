#include "webParse.h"

using namespace std;

WebParse::WebParse(int size, string websiteName){
    w.web = websiteName;
    w.weight = new int[size];
    w.adj = new string[size];
}

WebParse::~WebParse(){
	delete [] w.weight;
	delete [] w.adj;
}

string WebParse::getWeb(){
    return w.web;
}

string& WebParse::getAdj(){ //pass-by reference
    return *w.adj;
}

int& WebParse::getWeight(){ //pass-by reference
    return *w.weight;
}

ostream& operator<<(ostream& os, const WebParse& wp){
	os << "Website: " << wp.w.web.c_str() << " Adjacent: " << wp.w.adj.c_str() << " Weight: " << wp.w.weight;
	return os;
}
istream& operator>>(istream& is, const WebParse& wp){
	is >> wp.w.web;
	is >> wp.w.adj;
	is >> wp.w.weight;
	return is;
}

bool WebParse::operator==(const WebParse& wp) const{
	return(w.weight == wp.w.weight);

}
bool WebParse::operator!=(const WebParse& wp) const{
	return(w.weight != wp.w.weight);

}
bool WebParse::operator>=(const WebParse& wp) const{
	return(w.weight >= wp.w.weight);

}
bool WebParse::operator<=(const WebParse& wp) const{
	return(w.weight <= wp.w.weight);

}
bool WebParse::operator>(const WebParse& wp) const{
	return(w.weight > wp.w.weight);

}
bool WebParse::operator<(const WebParse& wp) const{
	return(w.weight < wp.w.weight);

}