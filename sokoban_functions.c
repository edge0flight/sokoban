#include "sokoban.h"

void destroy_character(_character character[])
{
	for(int i=0; i<MAX; i++)
	{
		sfSprite_destroy(character[i].sprite);
	}
}

void load_character(_character character[], sfTexture *texture)
{
	for(int i=0; i<MAX; i++)
	{
		sfIntRect area = {0,i*SIZE, SIZE, SIZE};
		character[i].area = area;
		character[i].sprite = sfSprite_create();
		sfSprite_setTexture(character[i].sprite, texture, sfFalse);
		sfSprite_setTextureRect(character[i].sprite, character[i].area);
	}
}

void draw_character(_character character[], sfRenderWindow *window, sfVector2f pos, enum direction direction)
{
	switch(direction)
	{
		case UP: sfSprite_setPosition(character[direction].sprite, pos);
		sfRenderWindow_drawSprite (window, character[direction].sprite, NULL);
		break;
		
		case DOWN: sfSprite_setPosition(character[direction].sprite, pos);
		sfRenderWindow_drawSprite (window, character[direction].sprite, NULL);
		break;
		
		case RIGHT: sfSprite_setPosition(character[direction].sprite, pos);
		sfRenderWindow_drawSprite (window, character[direction].sprite, NULL);
		break;
		
		case LEFT: sfSprite_setPosition(character[direction].sprite, pos);
		sfRenderWindow_drawSprite (window, character[direction].sprite, NULL);
		break;
		
		default: break;
	}
}