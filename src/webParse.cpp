#include "webParse.h"

using namespace std;

WebParse::WebParse(string webName){
    stringstream webstream(webName);
    webstream >> web;
    webstream >> adj;
    webstream >> weight;
}

string WebParse::getWeb(){
    return web;
}

string WebParse::getAdj(){
    return adj;
}

int WebParse::getWeight(){
    return weight;
}

friend ostream& operator<<(ostream& os, const WebParse& wp){
	os << "Website: " << wp.web.c_str() << " Adjacent: " << wp.adj.c_str() << " Weight: " << wp.weight;
	return os;
}
friend istream& operator>>(istream& is, const WebParse& wp){
	is >> wp.web;
	is >> wp.adj;
	is >> wp.weight;
	return is;
}

bool WebParse::operator==(const WebParse& wp) const{
	return(weight == wp.weight);

}
bool WebParse::operator!=(const WebParse& wp) const{
	return(weight != wp.weight);

}
bool WebParse::operator>=(const WebParse& wp) const{
	return(weight >= wp.weight);

}
bool WebParse::operator<=(const WebParse& wp) const{
	return(weight <= wp.weight);

}
bool WebParse::operator>(const WebParse& wp) const{
	return(weight > wp.weight);

}
bool WebParse::operator<(const WebParse& wp) const{
	return(weight < wp.weight);

}