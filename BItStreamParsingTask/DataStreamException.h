#pragma once
#include <string>
using namespace std;
class DataStreamException
{
public:
	DataStreamException(string exception_message = "");
	~DataStreamException();
};

