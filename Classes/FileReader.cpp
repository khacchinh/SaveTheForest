#include "FileReader.h"
#include <fstream>
#include "cocos2d.h"
#include <stdio.h>

using namespace cocos2d;
using namespace std;

FileReader::FileReader(){

}
void FileReader::readFile(){
	string line;
	ifstream myfile("HightScore.txt");
	if (myfile.is_open()){
		while (getline(myfile, line))
		{
			mFileContents.push_back(line);
		}
		myfile.close();
	}
	for (int i = 0; i < mFileContents.size(); i++)
	{
		log("%s",mFileContents.at(i).c_str());
	}
}
void FileReader::writeFile(string data){
	
	ofstream myfile("HightScore.txt");
	if (myfile.is_open())
	{
		myfile << data;
		myfile.close();
	}
	readFile();

	/*CCFileUtils *sharedFileUtils = CCFileUtils::sharedFileUtils();

	string line;
	string path = sharedFileUtils->fullPathForFilename("encoderTest.csv");
	ifstream myfile(path.c_str());
	ofstream outfile("filedamahoa.csv");
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			CCLog("Read: %s", line.c_str());
			string temp = convertBinaryToASCII(line);
			outfile << temp << "\n";
		}
		myfile.close();
		outfile.close();
	}

*/

	/*FILE *outfile;

	outfile = fopen("HightScore.txt", "w");
	for (int i = 0; i<10; i++) {
		fprintf(outfile, "%d\n", i + 1);
	}
	fclose(outfile);*/
}