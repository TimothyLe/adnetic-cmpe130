//Data Parser File Opener Header
#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include <string>
#include <sstream>
using namespace std;

class Website {
public:
	Website(string webName);
	string getWeb();
	string getAdj();
	int getWeight();
private:
	string web;
	string adj;
	int weight;
};

#endif

