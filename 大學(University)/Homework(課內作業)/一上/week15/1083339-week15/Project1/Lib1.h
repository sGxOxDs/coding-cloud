#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

#define MAXWORDLENGTH 255
struct dictionary {
	char word[MAXWORDLENGTH];
	unsigned int count;
};

void read(const char path[], const char igpath[], vector<dictionary>& data);
void run(vector< dictionary >& data);
void out(const char outpath[], vector< dictionary >& data);
bool existing(dictionary temp, const vector< dictionary >& data);

#endif
