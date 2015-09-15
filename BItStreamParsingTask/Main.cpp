#include <iostream>
#include <string>
#include <bitset>
#include "BitStreamConverter.h"
using namespace std;

void main()
{
	string str = "FF5FA5FCFC80DD57E5F8FDFF";
	auto a = BitStreamConverter::convert_to_bitset(str);
	BitStreamConverter::out(a, str.size()*8/2);
	cin.get();
}