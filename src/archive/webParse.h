//Data Parser File Opener Header
#ifndef _WEB_PARSE_
#define _WEB_PARSE_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <list>
using namespace std;

// struct webSite {
// 		int* weight;
// 		string* adj;
// 	}; 


class WebParse {
	string fileName;
public:
	WebParse(string _fileName) {fileName = _fileName;}
	int getFileSize();
	void webParser(string webName[], string adj[], int weight[]);

	// friend ostream& operator<<(ostream& os, const WebParse& wp);
	// friend istream& operator>>(istream& is, const WebParse& wp);
	
	// bool operator==(const WebParse& wp) const;
	// bool operator!=(const WebParse& wp) const;
	// bool operator>=(const WebParse& wp) const;
	// bool operator<=(const WebParse& wp) const;
	// bool operator>(const WebParse& wp) const;
	// bool operator<(const WebParse& wp) const;
};

#endif // _WEB_PARSE_

