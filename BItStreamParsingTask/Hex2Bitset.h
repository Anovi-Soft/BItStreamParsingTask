#pragma once
#include <vector>
using namespace std;
#define MAX_STREAM_BYTES 300


class Hex2Bitset
{
public:
	virtual vector<bool> convert(string &line) = 0;
	void check_line(string &line) const;
	Hex2Bitset();
	virtual ~Hex2Bitset();
};
