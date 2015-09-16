#include "DataStreamException.h"

char const* DataStreamException::what() const
{
	return nullptr;
}

DataStreamException::DataStreamException(string exception_message)
{
}

DataStreamException::~DataStreamException()
{
}