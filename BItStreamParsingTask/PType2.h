#pragma once
#include "PObject.h"
class PType2 :
	public PObject
{
public:
	std::string source(std::vector<bool>& bitset) override;
	PType2(int start, int length);
	~PType2();
};

