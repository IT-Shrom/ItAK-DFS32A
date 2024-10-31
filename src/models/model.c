#include <stdlib.h>
#include "model.h"
Card create_random_card() {
    Card card;
    card.level = (Level)(rand() % 3 + 1);
    card.color = (Color)(rand() % 10);
    card.force = (rand() % 5 + 2) * (card.level == LEVEL_3 ? 2 : 1);
    return card;
}
int can_play_card(Player *player, Card card, int row, int col) {
    if (row >= 3 || col >= 5 || player->tableau[row][col].level != 0)
        return 0;
    if ((card.level == LEVEL_1 && row != 1) ||
        (card.level == LEVEL_2 && (row != 2 || player->tableau[0][col].level != LEVEL_1)) ||
        (card.level == LEVEL_3 && (row != 3 || player->tableau[1][col].level != LEVEL_2)))
        return 0;
    return 1;
}
void play_card(Player *player, Card card, int row, int col) {
    player->tableau[row-1][col-1] = card;
    player->cards_played++;
}
int calculate_score(Player *player) {
    int score = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            score += player->tableau[i][j].force;
    return score;
}