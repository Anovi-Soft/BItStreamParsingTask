#include "ExtremePointsBitParser.h"
#include <vector>
#include "PType1.h"
#include "PType4.h"
#include "PType2.h"
using namespace std;


vector<PObject*> ExtremePointsBitParser::parse_objects(vector<bool>& bits)
///Non-readeble
{
	vector<PObject*> objects;
	vector<pair<int, bool>> extreme_points; // pair<start_point, value ? right_point : left_point>
	//Step 1
	//Find extreme points
	for (int i = 0; i < bits.size()-3; i++)
		if (bits[i + 1] && bits[i + 2])
			if (bits[i] && !bits[i + 3])
				extreme_points.push_back(make_pair(i, true));
			else if(!bits[i] && bits[i + 3])
				extreme_points.push_back(make_pair(i, false));

	int end_parse_bit = -1;
	//Step 2
	//Check first bitset to instance Type1 or Type4
	if (extreme_points[0].second && extreme_points[0].first>4)
	{
		if (all_true(bits, 0, extreme_points[0].first))
		{
			auto obj = new PType1(0, extreme_points[0].first + 3);
			objects.push_back(obj);
			end_parse_bit += obj->length;
		}
		else
		{
			auto obj = new PType4(0, extreme_points[0].first + 4);
			objects.push_back(obj);
			end_parse_bit += obj->length;
		}
		extreme_points.erase(extreme_points.begin());
	}

	//Check middle
	while(extreme_points.size()>1)
	{
		if (extreme_points.begin()->second)//right extreme point
		{
			extreme_points.erase(extreme_points.begin());
			continue;
		}
		if (end_parse_bit+1 != extreme_points[0].first)//free bits before extreme points(type4)
		{
			auto obj = new PType4(end_parse_bit + 1, extreme_points[0].first - 1 - end_parse_bit);
			end_parse_bit = extreme_points[0].first - 1;
			objects.push_back(obj);
		}
		if (!extreme_points[0].second && extreme_points[1].second)// pair of left and right extreme points (type1 or type2)
		{
			if (extreme_points[0].first + 4 == extreme_points[1].first)// pair side by side (type 2)
			{
				auto obj = new PType2(end_parse_bit + 1, 8);
				objects.push_back(obj);
				end_parse_bit += 8;
			}
			else if ((extreme_points[1].first - extreme_points[0].first > 5)&&
				(all_true(bits, extreme_points[0].first + 4, extreme_points[1].first)))//type 1
			{
				if (end_parse_bit+1 != extreme_points[0].first)
				{
					auto obj = new PType4(end_parse_bit + 1, 1);
					objects.push_back(obj);
					end_parse_bit += 1;
				}
				auto obj = new PType1(extreme_points[0].first, extreme_points[1].first - extreme_points[0].first + 2);
				objects.push_back(obj);
				end_parse_bit += obj->length;
			}
			extreme_points.erase(extreme_points.begin());
			extreme_points.erase(extreme_points.begin());			
		} 
	}

	//Check last bitset to instance Type1 or Type4
	if (!extreme_points.begin()->second && all_true(bits, extreme_points[0].first + 4, bits.size()))
	{
		if (end_parse_bit != extreme_points[0].first)
		{
			auto obj = new PType4(end_parse_bit + 1, 1);
			objects.push_back(obj);
			end_parse_bit += 1;
		}
		auto obj = new PType1(extreme_points[0].first, bits.size() - extreme_points[0].first + 2);
		objects.push_back(obj);
	}
	else
	{
		auto obj = new PType4(end_parse_bit + 1, bits.size() - end_parse_bit - 1);
		objects.push_back(obj);
	}
	//Step 3
	//
	return vector<PObject*>();
}

bool ExtremePointsBitParser::all_true(vector<bool>& bits, int start, int end )
{
	for (int i = start; i < end; i++)
		if (!bits[i])
			return false;
	return true;
}

ExtremePointsBitParser::ExtremePointsBitParser()
{
}

ExtremePointsBitParser::~ExtremePointsBitParser()
{
}
