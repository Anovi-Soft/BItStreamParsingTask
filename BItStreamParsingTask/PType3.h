#pragma once
#include "PObject.h"
class PType3 :
	public PObject
{
public:
	std::string source(std::vector<bool>& bitset) override;
	PType3(int start, int length);
	~PType3();
};

