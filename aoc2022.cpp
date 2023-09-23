#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

vector<int> aocChallenge1();
void aocChallenge2();

int main(int argc, char *argv[]){
    int parse = -1;
    try{
        parse = *argv[1] - '0';
    }
    catch (...){
        printf("Invalid input\n");
    }

    switch (parse){
        case 1:{
            printf("Challenge 1 Part 1: ");
            vector<int> challenge1Vector = aocChallenge1();
            printf("%d\n", challenge1Vector[challenge1Vector.size() - 1]);
            printf("Challenge 1 Part 2: ");
            int top3 = 0;
            for (int i = 3; i > 0; i--)
            {
                top3 += challenge1Vector[challenge1Vector.size() - i];
            }
            printf("%d\n", top3);
            break;
        }
        case 2:{
            printf("Challenge 2: ");
            aocChallenge2();
            break;
        }
        default:{
            printf("Invalid input must be from 1 to 2\n");
            break;
        }
    }

    return 0;
}

vector<int> aocChallenge1()
{
    fstream challenge1File;
    challenge1File.open("challenge1.txt", ios::in);

    string tp;
    int currentCalorieCount = 0;
    vector<int> elfCalorieList;

    if (challenge1File.is_open()){
        while (getline(challenge1File, tp)){
            if (!tp.empty()){
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

void aocChallenge2(){
    fstream challenge1File;
    challenge1File.open("challenge2.txt", ios::in);
    string tp;
    int totalScore = 0;
    int roundScore = 0;

    if (challenge1File.is_open()){

        while (getline(challenge1File, tp)){
            roundScore = 0;

            // Rock = 1 Point
            // Scissors = 2 Points
            // Paper = 3 Points
            switch (tp[0]){
                // Elf Played Rock
                case 'A':{
                    switch (tp[2]){
                        case 'X':{
                            // Player Played Rock
                            roundScore += 1 + 3;
                            break;
                        }
                        case 'Y':{
                            // Player Played Scissors
                            roundScore += 2;
                            break;
                        }
                        case 'Z':{
                            // Player Played Paper
                            roundScore += 3 + 6;
                            break;
                        }
                    }
                }
                case 'B':{
                // Elf Played Scissors
                    if(tp[2] == 'X'){
                        // Player Played Rock
                        roundScore += 1 + 6;
                    }
                    if(tp[2] == 'Y'){
                        // Player Played Scissors
                        roundScore += 2 + 3;
                    }
                    if(tp[2] == 'Z'){
                        // Player Played Paper
                        roundScore += 3;
                    }
                    break;
                }
                case 'C':{
                    // Elf Played Paper
                    if(tp[2] == 'X'){
                        // Player Played Rock
                        roundScore += 1;
                    }
                    if(tp[2] == 'Y'){
                        // Player Played Scissors
                        roundScore += 2 + 6;
                    }
                    if(tp[2] == 'Z'){
                        // Player Played Paper
                        roundScore += 3 + 3;
                    }
                    break;
                }
            }

            totalScore += roundScore;

        }

        challenge1File.close();

        printf("%d\n", totalScore);
    }
}