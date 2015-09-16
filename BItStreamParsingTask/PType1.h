#pragma once
#include "PObject.h"
class PType1 :
	public PObject
{
public:
	std::string source(std::vector<bool>& bitset) override;
	PType1(int start, int length);
	~PType1();
};

