#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#define SIZE (204/4)

#define WIDTH (SIZE*12)
#define HEIGHT (SIZE*12)

enum direction{DOWN,LEFT,RIGHT,UP,MAX};

typedef struct character _character;
struct character
{
	sfIntRect area;
	sfSprite *sprite;
};

void load_character(_character character[], sfTexture *texture);
void destroy_character(_character character[]);
void draw_character(_character character[], sfRenderWindow *window, sfVector2f pos, enum direction direction);

#endif