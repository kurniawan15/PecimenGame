#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define FOOD1_SCORE 15	//Titik
#define FOOD2_SCORE 100	//Sedap Malam
#define FOOD3_SCORE 300	//Menyan
#define FOOD4_SCORE 500	//Melati
#define FOOD5_SCORE 700	//Kopi Hitam

typedef struct{
	char *name;
	int score;
	int lives;
	pacmanController peciman;
} playerControl;

void initScore(playerControl *player);
void initLives(playerControl *player);
void incScore(int food, playerControl *player);
void eatFood(playerControl *player);
void incLives(playerControl *player);
int randomise(int min, int max);
int foodType(int x);
void addBonus(MapController *map, int posX, int posY);

#endif // SCORE_H_INCLUDED
