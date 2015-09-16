#pragma once
#include <iostream>
#include <vector>
#include "Hex2Bitset.h"
typedef unsigned char uchar;
using namespace std;




class BaseHex2Bitset:
	public Hex2Bitset
{
public:
	vector<bool> convert(string& line) override;

	virtual uchar hex2char(char &first, char &second);
	uchar hex2char(char &symbol);
	uchar invert(uchar byte);
};


inline uchar BaseHex2Bitset::hex2char(char& first, char& second)
{
	return invert(hex2char(first) * 16 + hex2char(second));
}