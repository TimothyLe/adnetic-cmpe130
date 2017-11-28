//File Parse
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <stack>
#include <limits.h>
#define NINF INT_MIN
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream ifs;
    ifs.open("test\\adsAPI (1).dat", ios::in); //open a file for reading
    ofstream ofs;
    ofs.open("parseOut.dat", ios::out); //open a file for output
    string dum,data;
    if(ifs.fail()){
        cout << "Error! File not found!" << endl;
        exit(1);
    }
    if(!ofs){
        cerr << "cannot open \"parseOut.dat\" for output\n";
        return -1;
    }
    getline(ifs, dum); //dummy data 1 line
    while(!ifs.eof()){
        getline(ifs, data);
        data = data.substr(0, data.find('['));
        if(isdigit(data[0])){
            istringstream iss(data);
        }
        ofs << data << endl;
    }
    ifs.close();
	return -1;
}