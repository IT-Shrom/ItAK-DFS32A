#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "controllers/controller.h"
/**
 * SHROM
 */
int main() {
    srand(time(NULL));
    Player player1 = {0};
    Player player2 = {0};
    game_loop(&player1, &player2);
    
    return 0;
}