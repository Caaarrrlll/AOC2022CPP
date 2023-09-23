#include<stdio.h>
#include<fstream>
#include<iostream>
#include<cctype>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

vector<int> aocChallenge1();

int main(int argc, char* argv[]) {
    int parse = -1;
    try{
        parse = *argv[1] - '0';
    } catch(...) {
        printf("Invalid input\n");
    }

    switch(parse){
        case 1: {
            printf("Challenge 1 Part 1: ");
            vector<int> challenge1Vector = aocChallenge1();
            printf("%d\n", challenge1Vector[challenge1Vector.size() - 1]);
            printf("Challenge 1 Part 2: ");
            int top3 = 0;
            for(int i = 3; i > 0; i--){
                top3 += challenge1Vector[challenge1Vector.size() - i];
            }
            printf("%d\n", top3);
            break;
        }
        default: {
            printf("Invalid input must be from 1 to 25\n");
            break;
        }
    }

    return 0;
}

vector<int> aocChallenge1(){
    fstream challenge1File;
    challenge1File.open("challenge1.txt", ios::in);

    string tp;
    int currentCalorieCount = 0;
    vector<int> elfCalorieList;

    if(challenge1File.is_open()){
        while(getline(challenge1File, tp)){ 
            if(!tp.empty()){
                currentCalorieCount += stoi(tp.c_str());
            }
            else{
                elfCalorieList.push_back(currentCalorieCount);
                currentCalorieCount = 0;
            }
        }

        challenge1File.close();

        sort(elfCalorieList.begin(), elfCalorieList.end());
    }

    return elfCalorieList;
}