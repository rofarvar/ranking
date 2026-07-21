#include <math.h>

float simulate (float teamA, float teamB) { //FIFA rankings-style simulation
    return 1/(pow(10, (-1 * (teamA - teamB))/600) + 1);
}

float simplesimulate (float teamA, float teamB) { //hyper-dumbed down simulation method
    return teamA/(teamA+teamB);
}

float chesssimulate (float teamA, float teamB) { //Chess-elo style simulation, much more variable
    return 1/(pow(10, (-1 * (teamA - teamB))/400) + 1);
}



