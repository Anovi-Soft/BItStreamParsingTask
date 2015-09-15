#include "BitStreamConverter.h"
#include "DataStreamException.h"


bitset<MaxStreamBytes * 8 / 2> BitStreamConverter::convert_to_bitset(string &line)
{
	if (line.size() > MaxStreamBytes)
		throw DataStreamException("More then " + to_string(MaxStreamBytes) + "bytes in input stream");
	if (line.size() & 1)
		throw DataStreamException("Half part of byte in input stream");
	if (!line.size())
		throw DataStreamException("Empty line in input stream");
	bitset<MaxStreamBytes * 8 / 2> bs;
	auto j = 0;
	for (auto i = 0; i < line.size(); i+=2)
	{
		auto part = hex2char(line[i], line[i + 1]);
		part = invert(part);
		for (uchar mask = 128; mask != 0; mask = mask >> 1)
			bs[j++] = part & mask;
	}
	return bs;
}

uchar BitStreamConverter::hex2char(char& symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return symbol - '0';
	if (symbol >= 'A' && symbol <= 'F')
		return symbol - 'A' + 10;
	if (symbol >= 'a' && symbol <= 'f')
		return symbol - 'a' + 10;
	throw DataStreamException("Unknown symbol: " + symbol);

}

inline uchar BitStreamConverter::hex2char(char& first, char& second)
{
	return hex2char(first) * 16 + hex2char(second);
}

uchar BitStreamConverter::invert(uchar byte)
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

void BitStreamConverter::out(bitset<300 * 8 / 2> btst, int count)
{
	for (auto i = 0; i < count; i++)
		cout << btst[i];
}

