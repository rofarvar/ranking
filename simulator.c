//A little elo-based simulator. The math is generally very easy here.
//This is a terrible metric for simulation. As in, it's very bad; but I like simulating things and elo's generally a good measure of a better team
//You can delete this file if you don't want it, nothing here impacts the rest of the project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulate.h"

int main (int argc, char * argv[]) {
    if (argc != 3) {
        printf("Uh-oh: your argument count is off. Try again. ");
    } else {
        char * country1 = argv[1];
        char * country2 = argv[2];
        float country1elo;
        float country2elo;

        FILE * elo1 = fopen(country1, "r");
        char buffer1[1024];
        country1elo = atof(fgets(buffer1, sizeof buffer1 , elo1));
        fclose(elo1);

        FILE * elo2 = fopen(country2, "r");
        char buffer2[1024];
        country2elo = atof(fgets(buffer2, sizeof buffer2, elo2));
        fclose(elo2);

        float country1winchance = simplesimulate(country1elo, country2elo);
        float country2winchance = simplesimulate(country2elo, country1elo);

        printf("%s win chance: %f%%\n", country1, country1winchance);
        printf("%s win chance: %f%%\n", country2, country2winchance);
    }
}