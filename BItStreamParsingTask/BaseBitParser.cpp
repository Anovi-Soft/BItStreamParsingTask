#include "BaseBitParser.h"

int BaseBitParser::how_much_true(vector<bool>& bits, int from)
{
	int i = from;
	for (; i < bits.size(); i++)
		if (!bits[i]) break;
	return i - from;
}

vector<PObject*> BaseBitParser::parse_objects(vector<bool>& bits)
{
	vector<pair<int, int>> filter;
	int i = 0;
	while (i < bits.size())
	{
		int length = how_much_true(bits, i);
		if (length)
		{
			if (length > 5)
				filter.push_back(make_pair(i,length));
			i += length;
		}
		else 
			i++;
	}




	return{};

}

BaseBitParser::BaseBitParser()
{
}


BaseBitParser::~BaseBitParser()
{
}
