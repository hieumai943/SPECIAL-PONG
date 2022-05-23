#include"object.h"
#include"game.h"

SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;





int main(int argc, char* args[]){

  Game game;
  
 game.init();
 


   game.rungame();

  

}