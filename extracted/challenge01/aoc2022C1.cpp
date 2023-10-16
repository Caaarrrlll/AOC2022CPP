#include <vector>
#include <fstream>

using namespace std;

vector<int> aocChallenge1()
{
    fstream challenge1File;
    challenge1File.open("extracted/challenge01/challenge01.txt", ios::in);

    string tp;
    int currentCalorieCount = 0;
    vector<int> elfCalorieList;

    if (challenge1File.is_open())
    {
        while (getline(challenge1File, tp))
        {
            if (!tp.empty())
            {
                currentCalorieCount += stoi(tp.c_str());
            }
            else
            {
                elfCalorieList.push_back(currentCalorieCount);
                currentCalorieCount = 0;
            }
        }

        challenge1File.close();

        sort(elfCalorieList.begin(), elfCalorieList.end());
    }

    return elfCalorieList;
}