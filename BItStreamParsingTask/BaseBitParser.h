#pragma once
#include<vector>
#include "BitParser.h"
using namespace std;


class BaseBitParser :
	public BitParser
{
	int how_much_true(vector<bool>& bits, int from);
	vector<PObject*> parse_objects(vector<bool>& bits) override;
public:
	BaseBitParser();
	~BaseBitParser();
};

