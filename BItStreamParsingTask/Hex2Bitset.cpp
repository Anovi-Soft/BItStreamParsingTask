#include "Hex2Bitset.h"
#include "DataStreamException.h"



void Hex2Bitset::check_line(string& line) const
{
	if (line.size() > MAX_STREAM_BYTES)
		throw DataStreamException("More then " + to_string(MAX_STREAM_BYTES) + "bytes in input stream");
	if (line.size() & 1)
		throw DataStreamException("Half part of byte in input stream");
	if (!line.size())
		throw DataStreamException("Empty line in input stream");
}

Hex2Bitset::Hex2Bitset()
{
}


Hex2Bitset::~Hex2Bitset()
{
}
