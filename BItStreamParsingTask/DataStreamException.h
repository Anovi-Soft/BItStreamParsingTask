#pragma once
#include <string>
using namespace std;
class DataStreamException:exception
{
public:
	char const* what() const override;
	DataStreamException(string exception_message = "");
	~DataStreamException();
};

