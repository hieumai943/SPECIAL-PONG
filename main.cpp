#include"object.h"
#include"game.h"
#include"menu.h"

    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font* font;
    Game game;
int main(int argc, char* args[]){
     game.restart=1;
while(game.restart==1){
     game.variable();
     game.serve();
     game.runMenu();
   if(game.run!=1)
     game.rungame();
     game.runback();
     game.start=0;
  }
 }