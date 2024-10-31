#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controller.h"
#include "../views/view.h"

void game_loop(Player *player1, Player *player2) {
    int turn = 0;
    int moves = 0;
    while (moves < 15) {
        Player *current_player = (turn % 2 == 0) ? player1 : player2;
        int  turnPlayer = (turn % 2 == 0) ? 1 : 2;
        Card drawn_card = create_random_card();
        printf("\nPlayer %d c'est votre tour ! \n\n", turnPlayer);
        printf("Carte piochee : ");
        print_card(drawn_card);
        printf("\nChoisissez une position (ligne colonne) ou -1 pour passer : ");
        int row, col;
        scanf("%d", &row);
        if (row == -1) {
            turn++;
            continue;
        }
        scanf("%d", &col);
        if (can_play_card(current_player, drawn_card, row, col)) {
            play_card(current_player, drawn_card, row, col);
            display_game_state(player1, player2);
            moves++;
        } else {
            printf("Mouvement invalide. Reessayez.\n");
        }
        turn++;
    }
    int score1 = calculate_score(player1);
    int score2 = calculate_score(player2);
    printf("Score Joueur 1 : %d\nScore Joueur 2 : %d\n", score1, score2);
    if (score1 > score2)
        printf("Joueur 1 gagne !\n");
    else if (score2 > score1)
        printf("Joueur 2 gagne !\n");
    else
        printf("Égalite !\n");
}