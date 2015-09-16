#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include "BaseHex2Bitset.h"
#include "MapHex2Bitset.h"
#include <map>
#include "ExtremePointsBitParser.h"
using namespace std;

void main()
{
	string s = "FF5FA5FCFC80DD57E5F8FDFF";
	auto a = MapHex2Bitset().convert(s);
	ExtremePointsBitParser().Parse(a);

}




//TMP 
//unsigned char int2hex(char i)
//{
//	if (i < 10)
//		return '0' + i;
//	return 'A' + i - 10;
//}
//
//vector<string> random_lines()
//{
//	srand(time(nullptr));
//	vector<string> result;
//	for (int i = 0; i < 100000; i++)
//	{
//		result.push_back("");
//		for (int j = 0; j < MAX_STREAM_BYTES; j++)
//			result[i] += int2hex(rand() % 16);
//	}
//	return result;
//}
//
//int speed_test(Hex2Bitset &con)
//{
//	auto lines = random_lines();
//	auto start_t = clock();
//	for (auto line : lines)
//		con.convert(line);
//	return clock() - start_t;
//}
//
//void main()
//{
//	auto a = MapHex2Bitset();
//	auto b = BaseHex2Bitset();
//	a.test();
//	cout << "MapHex2Bitset: " << speed_test(a) <<"ms"<< endl; // 19000
//	cout << "BaseHex2Bitset: " << speed_test(b) <<"ms"; // 15000
//	cin.get();
//}

//void main()
//{
//	ofstream os("tmp.txt");
//	os << "{\n";
//	string simbs = "0123456789ABCDEF";
//	for (char i = 0; i < 16; i++)
//		for (char j = 0; j < 16; j++)
//		{
//			os << "\t{{'" << simbs[i] << "','" <<  simbs[j] << "'},{";
//			auto part = BaseHex2Bitset().hex2char(simbs[i], simbs[j]);
//			for (uchar mask = 128; mask != 0; mask = mask >> 1)
//				os << ((part & mask)!=0) << ",";
//			os << "}},\n";
//		}
//	os << "};";
//
//	os.close();
//}
