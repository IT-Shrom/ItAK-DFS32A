#include <stdio.h>
#include "view.h"
void print_card(Card card) {
    const char *colors[] = { "Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert" };
    printf("%d-%s-%d", card.level, colors[card.color], card.force);
}
void display_game_state(Player *player1, Player *player2 ) {
    printf("Tableau du Joueur 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (player1->tableau[i][j].level)
                print_card(player1->tableau[i][j]);
            else
                printf(" . ");
            printf("\t");
        }
        printf("\n");
    }
    printf("Tableau du Joueur 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (player2->tableau[i][j].level)
                print_card(player2->tableau[i][j]);
            else
                printf(" . ");
            printf("\t");
        }
        printf("\n");
    }
}