#pragma once
#include <iostream>
#include <string>
#include <bitset>
#define MaxStreamBytes 300
typedef unsigned char uchar;
using namespace std;




class BitStreamConverter
{
	static bitset<MaxStreamBytes * 8 / 2> convert_to_bitset(string &line);
	static uchar hex2char(char &symbol);
	static uchar hex2char(char &first, char &second);
	static uchar invert(uchar byte);

public:
	BitStreamConverter();
	~BitStreamConverter();
	void redirect(istream input_stream, ostream output_stream);
	void test();
};

