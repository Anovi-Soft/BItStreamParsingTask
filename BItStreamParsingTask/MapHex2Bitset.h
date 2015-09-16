#pragma once
#include "BaseHex2Bitset.h"
#include <map>

class MapHex2Bitset :
	public Hex2Bitset
{
public:
	vector<bool> convert(string& line) override;

	MapHex2Bitset();
	~MapHex2Bitset();
	void test();
private :
	map<string, vector<bool> > hash_map;
	vector<bool> hex2bit(char& first, char& second);
};


inline vector<bool> MapHex2Bitset::hex2bit(char& first, char& second)
{
	return hash_map[{first,second}];
}

inline void MapHex2Bitset::test()
{
	cout << (sizeof(string) + sizeof(bool) * 8) * 16 * 16 << endl;
}
