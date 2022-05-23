#ifndef MENU_H
#define MENU_H
#include"object.h"

const int WIDTH= 1000;
const int HEIGHT= 600;
const int FONT_SIZE= 56;

class Menu{
     
     public:
  
string level1,level2,mode1,mode2;
string score0,score1,score2,score3;
Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
bool running=1;
SDL_Color color;
SDL_Rect score_board;
int easy;

Object hnen;
     void init();
     void draw(Object o);
     void write(string text, int x, int y);
     void renderMenu();

     void inputmenu();
     void runmenu();
private:
SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;


};
#endif