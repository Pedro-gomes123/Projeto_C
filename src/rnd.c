#include <stdlib.h>
#include <time.h>
#include "rnd.h"

void setup_random() {

    srand(time(NULL));
}

int roll_dice(int max) {

    return rand() % max;
}