#ifndef MENU_H
#define MENU_H
#include"object.h"

const double SIZE= 17;
const double BALL_SPEED= 16;
const double SPEED = 12;
const double PI = 3.14;
const int WIDTH= 1000;
const int HEIGHT= 600;
const int FONT_SIZE= 56;

class Menu{
 private:
 SDL_Renderer *renderer;
 SDL_Window *window;
 TTF_Font* font;


public:
Menu();
~Menu();
SDL_Color color;
Object hnen;
bool running;
SDL_Rect score_board;
string level1,level2,mode1,mode2;
string score,score0,score1,score2,score3;
int easy=0;

    
     void draw(Object o);
     void write(string text, int x, int y);
   
     void renderMenu();
      
     void inputmenu();
     void run();
};
 
#endif