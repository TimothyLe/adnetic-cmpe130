//Data Parser File Opener Header
#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include <string>
#include <sstream>
using namespace std;

class WebParse {
public:
	WebParse(string webName);
	~WebParse();
	string getWeb();
	string getAdj();
	int getWeight();

	friend ostream& operator<<(ostream& os, const WebParse& wp);
	friend istream& operator>>(istream& is, const WebParse& wp);
	
	bool operator==(const WebParse& wp) const;
	bool operator!=(const WebParse& wp) const;
	bool operator>=(const WebParse& wp) const;
	bool operator<=(const WebParse& wp) const;
	bool operator>(const WebParse& wp) const;
	bool operator<(const WebParse& wp) const;
private:
	string web;
	string adj[];
	int weight[];
};

#endif

