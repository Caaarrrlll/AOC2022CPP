#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

void aocChallenge3()
{
	map<char, int> compartmentMap = {
		{'a', 1},
		{'b', 2},
		{'c', 3},
		{'d', 4},
		{'e', 5},
		{'f', 6},
		{'g', 7},
		{'h', 8},
		{'i', 9},
		{'j', 10},
		{'k', 11},
		{'l', 12},
		{'m', 13},
		{'n', 14},
		{'o', 15},
		{'p', 16},
		{'q', 17},
		{'r', 18},
		{'s', 19},
		{'t', 20},
		{'u', 21},
		{'v', 22},
		{'w', 23},
		{'x', 24},
		{'y', 25},
		{'z', 26},
		{'A', 27},
		{'B', 28},
		{'C', 29},
		{'D', 30},
		{'E', 31},
		{'F', 32},
		{'G', 33},
		{'H', 34},
		{'I', 35},
		{'J', 36},
		{'K', 37},
		{'L', 38},
		{'M', 39},
		{'N', 40},
		{'O', 41},
		{'P', 42},
		{'Q', 43},
		{'R', 44},
		{'S', 45},
		{'T', 46},
		{'U', 47},
		{'V', 48},
		{'W', 49},
		{'X', 50},
		{'Y', 51},
		{'Z', 52}};

	ifstream challenge2File;
	// challenge2File.open("extracted/challenge03/challenge03.txt", ios::in);
	challenge2File.open("extracted/challenge03/sample.txt", ios::in);

	if (challenge2File.is_open())
	{
		int totalPriority = 0;
		string tp;

		// *** Part 1 *** //
		// while (getline(challenge2File, tp))
		// {
		// 	string compartment1 = tp.substr(0, tp.length() / 2);
		// 	string compartment2 = tp.substr((tp.length() / 2), tp.length() / 2);

		// 	vector<char> matchingPriorities = vector<char>();

		// 	for (int i = 0; i < compartment1.length(); i++)
		// 	{
		// 		for (int j = 0; j < compartment2.length(); j++)
		// 		{
		// 			if (compartment1[i] == compartment2[j])
		// 			{
		// 				matchingPriorities.push_back(compartment1[i]);
		// 			}
		// 		}
		// 	}

		// 	auto it = unique(matchingPriorities.begin(), matchingPriorities.end());

		// 	matchingPriorities.resize(distance(matchingPriorities.begin(), it));

		// 	for (int k = 0; k < matchingPriorities.size(); k++)
		// 	{
		// 		totalPriority += compartmentMap[matchingPriorities[k]];
		// 	}
		// }

		// *** Part 2 *** //
		int lineCount = 0;
		map<int, string> elves;
		while (getline(challenge2File, elves[lineCount++]))
		{
			if(lineCount >= 3){

			}
		}

		printf("Total Priority: %d\n", totalPriority);
	}

	challenge2File.close();
}

int calcPriorities(map<int, string> elfTeam){


	return 0;
}