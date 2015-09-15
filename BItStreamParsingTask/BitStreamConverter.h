#pragma once
#include <iostream>
#include <string>
#include <bitset>
#define MaxStreamBytes 300
typedef unsigned char uchar;
using namespace std;




class BitStreamConverter
{
	static uchar hex2char(char &first, char &second);

public:

	static bitset<MaxStreamBytes * 8 / 2> convert_to_bitset(string &line);
	static uchar hex2char(char &symbol);
	static uchar invert(uchar byte);
	
	static void out(bitset<MaxStreamBytes * 8 / 2> btst, int count);
};

