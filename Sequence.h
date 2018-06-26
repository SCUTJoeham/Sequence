#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

class Sequence
{
public:
	Sequence();
	Sequence(const char *filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
	int comlen(const char *p,const char *q);

	string sequence;
	
};

#endif
