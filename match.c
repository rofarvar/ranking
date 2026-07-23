#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulate.h"

int main(int argc, char * argv[]) {
    if (argc != 5) {
        printf("Usage: ./match Who_Won Who_Lost matchType result\n Go to the readme for more");
    } else {
        char * win = argv[1];
        char * lose = argv[2];
        char * matchType = argv [3];
        char * result = argv[4];
        float winnerMatchResult;
        float loserMatchResult;
        int matchWeight;
        float winnerExpectancy;
        float loserExpectancy;

    
        if (strcmp(result, "regular") == 0) {
            winnerMatchResult = 1;
            loserMatchResult = 0;
        } else if (strcmp(result, "draw") == 0) {
            winnerMatchResult = 0.5;
            loserMatchResult = 0.5;
        } else if (strcmp(result, "penalties") == 0) {
            winnerMatchResult = 0.75;
            loserMatchResult = 0.5;
        } else {
            printf("Match type not found");
            exit(0);
        }


        if (strcmp(matchType, "outFriendly") == 0) {
            matchWeight = 5;
        } else if (strcmp(matchType, "friendly") == 0) {
            matchWeight = 10;
        } else if (strcmp(matchType, "championsGroup") == 0) {
            matchWeight = 15;
        } else if (strcmp(matchType, "qualifier") == 0) {
            matchWeight = 25;
        } else if (strcmp(matchType, "group") == 0) {
            matchWeight = 35;
        } else if (strcmp(matchType, "round") == 0) {
            matchWeight = 40;
        } else if (strcmp(matchType, "quarter") == 0) {
            matchWeight = 50;
        } else if (strcmp(matchType, "finals") == 0) {
            matchWeight = 60;
        } else {
            printf("Match type not found. ./help for more info");
            exit(0);
        }

        FILE * winningCountry = fopen(win, "r");
        char buffer[1024];
        float winOG = atof(fgets(buffer, sizeof buffer, winningCountry));
        fclose (winningCountry);

        FILE * losingCountry = fopen(lose, "r");
        char buffer2[1024];
        float loseOG = atof(fgets(buffer2, sizeof buffer, losingCountry));
        fclose (losingCountry);

        if (winOG > loseOG) {
            winnerExpectancy = simulate(winOG, loseOG);
            loserExpectancy = 1 - winnerExpectancy;
        } else if (winOG < loseOG) {
            loserExpectancy = simulate(loseOG, winOG);
            winnerExpectancy = 1 - loserExpectancy;
        } else if (winOG == loseOG) {
            winnerExpectancy = 0.5;
            loserExpectancy = 0.5;
        } else {
            printf("This is an error and you manually inputed some weird values into the country files. Check them.\n");
            exit(0);
        }

        float winnerFinalElo = winOG + matchWeight * (winnerMatchResult - winnerExpectancy);
        float loserFinalElo = loseOG + matchWeight * (loserMatchResult - loserExpectancy);

        FILE * finalWinnerElo = fopen(win, "w");
        char buffer3[1024];
        fprintf(finalWinnerElo, "%f", winnerFinalElo);
        fclose(finalWinnerElo);
        printf("%s elo: %f\n", win, winnerFinalElo);

        FILE * finalLoserElo = fopen(lose, "w");
        if (loserFinalElo <= 0) {
            fprintf(finalLoserElo, "0");
            fclose(finalLoserElo);
            printf("%s elo: 0\n", lose);
        } else {
            char buffer4[1024];
            fprintf(finalLoserElo, "%f", loserFinalElo);
            fclose(finalLoserElo);
            printf("%s elo: %f\n", lose, loserFinalElo);
        }
    }
}