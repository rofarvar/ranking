// Just like the simple simulator simulator.c, this is very unnecessary. If you would like to remove it, please go ahead and do so.
#include "simulate.h";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Uh-oh! Something went wrong. Try again with different values, or try ./simulator for the Simple Simulator");
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

        float winner;
        float loser;

        if (country1elo > country2elo) {
            winner = simulate(country1elo, country2elo);
            loser = 1 - winner;

            printf("%s has the highest win chance of %f%%", country1, winner);
        } else if (country1elo < country2elo) {
            loser = simulate(country1elo, country2elo);
            winner = 1 - loser;

            printf("%s is the underdog with a win chance of %f%%", country2, loser);
        } else if (country1elo == country2elo) {
            winner = 0.5;
            loser = 0.5;
            
            printf("It's a 50/50 shot!");
        } else {
            printf("This is an error and you manually inputed some weird values into the country files. Check them.\n");
        }

        
    }
}