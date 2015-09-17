#pragma once
#include "BaseHex2Bitset.h"
#include <map>

class MapHex2Bitset :
	public Hex2Bitset
{
	map<string, vector<bool> > hash_map;
	vector<bool> hex2bit(char& first, char& second);
public:
	vector<bool> convert(string& line) override;
	MapHex2Bitset();
	~MapHex2Bitset();
};


inline vector<bool> MapHex2Bitset::hex2bit(char& first, char& second)
{
	return hash_map[{first,second}];
}

