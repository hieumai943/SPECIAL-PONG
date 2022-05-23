#include"object.h"
#include"menu.h"
#include"game.h"
SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;


Menu menu;
Game game;

int main(int argc, char* args[]){

 menu.init();

 game.menu.easy=1;

game.rungame();

game.close();
}