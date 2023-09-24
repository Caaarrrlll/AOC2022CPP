#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

#include "extracted/aoc2022C1.cpp"
#include "extracted/aoc2022C2.cpp"
#include "extracted/aoc2022C3.cpp"

using namespace std;

// vector<int> aocChallenge1();
// void aocChallenge2();
// void aocChallenge3();

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
            printf("Challenge 3: \n");
            aocChallenge3();
            break;
        }
        default:{
            printf("Invalid input must be from 1 to 2\n");
            break;
        }
    }

    return 0;
}