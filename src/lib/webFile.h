//Data Parser File Opener Header
#ifndef _WEB_FILE_
#define _WEB_FILE_

#include <string>
#include <algorithm>
#include <fstream>
#include "webParse.h"
using namespace std;


class WebFile : public WebParse{
public:
	WebFile(string filePath, int len);
	
	WebParse getWebsites();
	list<WebParse> getAdjacents();
	list<WebParse> getWeights();
private:
	list<WebParse> webs;
};

#endif

