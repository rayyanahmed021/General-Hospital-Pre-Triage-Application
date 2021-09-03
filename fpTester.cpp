// Final Project Tester
// file: fpTester.cpp
// Version: 1.0
// Date: 2021-06-23
// Author: Fardad
// Description:
// This file tests the Final project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <crtdbg.h>
#include <cstdlib>
#include "PreTriage.h"
#include "utils.h"
using namespace std;
using namespace sdds;
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void copyFile(const char* des, const char* src) {
   ifstream s(src);
   ofstream d(des);
   char ch = 0;
   while (s.get(ch) && d << ch);
}
void fp1tester() {
   ofstream("data.csv").close();
   sdds::debug = true;
   PreTriage P("data.csv");
   P.run();
}
void fp2tester() {
   copyFile("smalldata.csv", "smalldata.csv.bak");
   sdds::debug = true;
   PreTriage P("smalldata.csv");
   P.run();
}
void fp3tester() {
   copyFile("bigdata.csv", "bigdata.csv.bak");
   sdds::debug = true;
   PreTriage P("bigdata.csv");
   P.run();
}
int main() {
	//3770
	//3769
	//3766
	/*_CrtSetBreakAlloc(3770);
	_CrtSetBreakAlloc(3769);
	_CrtSetBreakAlloc(3766);*/
   /*fp1tester();
   displayFile("data.csv");
   fp3tester();
   displayFile("bigdata.csv");*/
   fp2tester();
   displayFile("smalldata.csv");
   _CrtDumpMemoryLeaks();
   return 0;
}

