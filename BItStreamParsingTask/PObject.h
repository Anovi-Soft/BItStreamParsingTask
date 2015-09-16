#pragma once
#include <string>
#include <vector>


class PObject
{
	unsigned char char2Hex(char num) const;
public:
	PObject(int start, int length);
	virtual ~PObject()
	{
	}
	int start;
	int length;
	char type;
	virtual std::string source(std::vector<bool> &bitset) = 0;

};

