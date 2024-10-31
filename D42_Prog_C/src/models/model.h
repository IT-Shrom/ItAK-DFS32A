#ifndef MODEL_H
#define MODEL_H

typedef enum {
    BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT
} Color;

typedef enum {
    LEVEL_1 = 1, LEVEL_2, LEVEL_3
} Level;

typedef struct {
    Level level;
    Color color;
    int force;
} Card;

typedef struct{
    Card tableau[3][5];
    int cards_played;
}Player;

Card create_random_card();
int can_play_card(Player *player, Card card, int row, int col);
void play_card(Player *player, Card card, int row, int col);
int calculate_score(Player *player);

#endif