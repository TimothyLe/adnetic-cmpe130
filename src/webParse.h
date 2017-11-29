//Data Parser File Opener Header
#ifndef _FILE_PARSER_
#define _FILE_PARSER_

#include <string>
#include <sstream>
#include <list>
using namespace std;

struct webSite {
		string web;
		int* weight;
		string* adj;
	};


class WebParse {
public:
	WebParse(int size, string websiteName);
	~WebParse();
	string getWeb();
	string& getAdj();
	int& getWeight();

	friend ostream& operator<<(ostream& os, const WebParse& wp);
	friend istream& operator>>(istream& is, const WebParse& wp);
	
	bool operator==(const WebParse& wp) const;
	bool operator!=(const WebParse& wp) const;
	bool operator>=(const WebParse& wp) const;
	bool operator<=(const WebParse& wp) const;
	bool operator>(const WebParse& wp) const;
	bool operator<(const WebParse& wp) const;
private:
	webSite w;
};

#endif

