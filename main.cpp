#include"object.h"
#include"game.h"
#include"menu.h"

    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font* font;

    Game game;

int main(int argc, char* args[]){
  
    game.init();
    game.variable();
    game.serve();
    game.runMenu();
    game.rungame();
    game.close();
 }