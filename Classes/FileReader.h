#include "cocos2d.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace cocos2d;

class FileReader {
public:
	FileReader();
	vector< string > mFileContents;
	void readFile();
	void writeFile(string data);

};