#include <fstream>

using namespace std;
 
void aocChallenge3(){
	fstream challenge2File;
    challenge2File.open("challenge3.txt", ios::in);
    string tp;
	string compartment1;
	string compartment2;

    if (challenge2File.is_open()){
        while(getline(challenge2File, tp)){
            printf("%s\n", tp.c_str());
			compartment1 = tp.substr(0, tp.length() / 2);
			compartment2 = tp.substr((tp.length() / 2) - 1, tp.length() / 2);

			printf("%s\n", compartment1.c_str());
			printf("%s\n", compartment2.c_str());
		}
	}
}