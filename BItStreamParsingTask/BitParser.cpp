#include "BitParser.h"


std::string BitParser::Parse(std::vector<bool> &bits)
{
	std::string result;
	for (auto obj : parse_objects(bits))
		result += obj->source(bits);
	return result;
}

BitParser::BitParser()
{
}


BitParser::~BitParser()
{
}
