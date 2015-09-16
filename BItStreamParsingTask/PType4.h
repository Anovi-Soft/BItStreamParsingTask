#pragma once
#include "PObject.h"
class PType4 :
	public PObject
{
public:
	std::string source(std::vector<bool>& bitset) override;
	PType4(int start, int length);
	~PType4();
};

