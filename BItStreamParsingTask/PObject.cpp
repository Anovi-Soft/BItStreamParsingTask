#include "PObject.h"


unsigned char PObject::char2Hex(char num) const
{
		if (num < 10)
			return '0' + num;
		return 'A' + num - 10;
}

PObject::PObject(int start, int length)
{
	this->start = start;
	this->length = length;
}