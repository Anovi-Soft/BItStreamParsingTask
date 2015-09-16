#include "BaseHex2Bitset.h"
#include "DataStreamException.h"


vector<bool> BaseHex2Bitset::convert(string& line)
{
	check_line(line);
	vector<bool> bs;
	auto j = 0;
	for (auto i = 0; i < line.size(); i += 2)
	{
		auto part = hex2char(line[i], line[i + 1]);
		for (uchar mask = 128; mask != 0; mask = mask >> 1)
			bs.push_back(part & mask);
	}
	return bs;
}

uchar BaseHex2Bitset::hex2char(char& symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return symbol - '0';
	if (symbol >= 'A' && symbol <= 'F')
		return symbol - 'A' + 10;
	if (symbol >= 'a' && symbol <= 'f')
		return symbol - 'a' + 10;
	throw DataStreamException("Unknown symbol: " + symbol);

}



uchar BaseHex2Bitset::invert(uchar byte)
{
	auto base = 256;
	uchar res = 0;
	while (byte != 0)
	{
		res += (byte & 1) * (base >>= 1);
		byte >>= 1;
	}
	return res;
}


