#ifndef GAME_H
#define GAME_H


#include"object.h"
#include"menu.h"

const double SIZE= 16;
const double BALL_SPEED= 16;
const double SPEED = 12;
const double PI = 3.14;



class Game{
   public:
  

SDL_Rect l_paddle, r_paddle, ball ,tuong,tuong1;
SDL_Color color;
SDL_Rect score_board;

Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
int frameCount, timerFPS, lastFrame, fps;
Object bgr,hnen,wall,wall1;
double vX, vY;
string score;

bool running=1;
int lastTime=0;
int l_s, r_s;// diem trai va diem phai
bool turn =1;
Menu menu;
void init();
void variable();
void serve();
void draw(Object o);

void update();
void inputgame();
void rendergame();
void rungame();
void close();
  

   private:

SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;


};
#endif