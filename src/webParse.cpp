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