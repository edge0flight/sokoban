#include "sokoban.h"

int main (int argc, char **argv)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow* window;
	sfTexture *texture;
	
   	_character hero[MAX];
	enum direction direction = RIGHT;
	
	window = sfRenderWindow_create(mode, "Sokoban", sfClose, NULL);
	texture = sfTexture_createFromFile("sprites.png", NULL);
	
	load_character(hero, texture);
	sfVector2f pos = {0, 0};
	
	while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
		
        while (sfRenderWindow_pollEvent(window, &event))
       	{
			switch(event.type)
            {
				case sfEvtClosed: sfRenderWindow_close(window);
				break;
				
				case sfEvtKeyPressed:
				switch (event.key.code)
				{
					case sfKeyRight: pos.x += SIZE;
					direction = RIGHT;
					break;
					
					case sfKeyLeft: pos.x -= SIZE;
					direction = LEFT;
					break;
					
					case sfKeyUp: pos.y -= SIZE;
					direction = UP;
					break;
					
					case sfKeyDown: pos.y += SIZE;
					direction = DOWN;
					break;
					
					default: break;
				}
				break;
				
				default: break;
			}
       	}
        
        sfRenderWindow_clear(window, sfBlue);
		draw_character(hero, window, pos, direction);
		sfRenderWindow_display (window);
	}

	destroy_character(hero);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
	return 0;
}