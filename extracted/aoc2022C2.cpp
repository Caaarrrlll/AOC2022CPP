#include <fstream>

using namespace std;

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