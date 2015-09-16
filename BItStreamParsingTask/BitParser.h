#pragma once
#include <vector>
#include "PObject.h"

class BitParser
{
	virtual std::vector<PObject*>parse_objects(std::vector<bool> &bits)=0;
public:
	std::string Parse(std::vector<bool> &bits);
	BitParser();
	virtual ~BitParser();
};

