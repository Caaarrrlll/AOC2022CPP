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
void challenge3();

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
            printf("See Comments in Challenge 2 for description on part one and 2\n");
            printf("Challenge 2: ");
            aocChallenge2();
            break;
        }
        case 3: {
            printf("Challenge 3: ");
            challenge3();
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
    fstream challenge2File;
    challenge2File.open("challenge2.txt", ios::in);
    string tp;
    int totalScore = 0;
    int roundScore = 0;

    if (challenge2File.is_open()){
        // *** Part 1 *** //
        // while (getline(challenge1File, tp)){
        //     roundScore = 0;

        //     // Rock for player = 1 Point
        //     // Paper for player= 2 Points
        //     // Scissors for player = 3 Points

        //     // 0 Points for loss = X
        //     // 3 Points for tie = Y
        //     // 6 Points for win = Z

        //     switch (tp[2]){
        //         case 'X':{
        //             // Player Played Rock
        //             roundScore += 1;
        //             if(tp[0] == 'A'){
        //                 // Computer Played Rock
        //                 roundScore += 3;
        //             }
        //             if(tp[0] == 'B'){
        //                 // Computer Played Paper
        //                 roundScore += 0;
        //             }
        //             if(tp[0] == 'C'){
        //                 // Computer Played Scissors
        //                 roundScore += 6;
        //             }
        //             break;
        //         }
        //         case 'Y':{
        //             // Player Played Paper
        //             roundScore += 2;
        //             if(tp[0] == 'A'){
        //                 // Computer Played Rock
        //                 roundScore += 6;
        //             }
        //             if(tp[0] == 'B'){
        //                 // Computer Played Paper
        //                 roundScore += 3;
        //             }
        //             if(tp[0] == 'C'){
        //                 // Computer Played Scissors
        //                 roundScore += 0;
        //             }
        //             break;
        //         }
        //         case 'Z':{
        //             // Player Played Scissors
        //             roundScore += 3;
        //             if(tp[0] == 'A'){
        //                 // Computer Played Rock
        //                 roundScore += 0;
        //             }
        //             if(tp[0] == 'B'){
        //                 // Computer Played Paper
        //                 roundScore += 6;
        //             }
        //             if(tp[0] == 'C'){
        //                 // Computer Played Scissors
        //                 roundScore += 3;
        //             }
        //             break;
        //         }
        //         default:{
        //             printf("Invalid input\n");
        //             break;
        //         }
        //     }
        //     totalScore += roundScore;
        // }

        // *** Part 2 *** //
        while(getline(challenge2File, tp)){
            printf("%s\n", tp.c_str());
            roundScore = 0;

            // Rock for player = 1 Point
            // Paper for player= 2 Points
            // Scissors for player = 3 Points

            // 0 Points for loss = X
            // 3 Points for tie = Y
            // 6 Points for win = Z
            switch (tp[0]){
                case 'A':{
                    // Elf Played Rock
                    if(tp[2] == 'X'){
                        // Player Plays Scissors
                        roundScore += 3;
                    }
                    if(tp[2] == 'Y'){
                        // Player Plays Rock
                        roundScore += 1;
                        roundScore += 3;
                    }
                    if(tp[2] == 'Z'){
                        // Player Plays Paper
                        roundScore += 2;
                        roundScore += 6;
                    }
                    break;
                }
                case 'B':{
                    // Elf Played Paper
                    if(tp[2] == 'X'){
                        // Player Plays Rock
                        roundScore += (1);
                    }
                    if(tp[2] == 'Y'){
                        // Player Plays Paper
                        roundScore += (2 + 3);
                    }
                    if(tp[2] == 'Z'){
                        // Player Plays Scissors
                        roundScore += (3 + 6);
                    }
                    break;
                }
                case 'C':{
                    // Elf Played Scissors
                    if(tp[2] == 'X'){
                        // Player Plays Paper
                        roundScore += (2);
                    }
                    if(tp[2] == 'Y'){
                        // Player Plays Scissors
                        roundScore += (3 + 3);
                    }
                    if(tp[2] == 'Z'){
                        // Player Plays Rock
                        roundScore += (1 + 6);
                    }
                    break;
                }
                default: break;
            }

            totalScore += roundScore;
        }

        challenge2File.close();
        printf("%d\n", totalScore);
    }
}

void challenge3(){}