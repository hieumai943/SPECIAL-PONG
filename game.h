#ifndef GAME_H
#define GAME_H

#include"object.h"
#include"menu.h"
class Game{
   public:
Game();
~Game();
SDL_Color color;

bool running;

SDL_Rect l_paddle, r_paddle, ball ,tuong,tuong1;

SDL_Rect score_board;

int frameCount, timerFPS, lastFrame, fps;
Object bgr,bgrMenu,bgr2,wall,wall1,m_ball,m_ball2,play,over,win,play1,play2;
double vX, vY;
string score,level1,level2,score1,mode1,mode2,score2,score3;
int lastTime=0;
int l_s, r_s;// diem trai va diem phai
bool turn ;
Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
int easy,mode,start,restart,run;
int count=0,count1=0;

void variable();
void serve();
void draw(Object o);
void DRAW(const char*msg,int x, int y, int r, int g, int b ,int size);
void inputMenu();
void renderMenu();
void runMenu();
void update();
void inputgame();
void write(string text, int x, int y,int r, int g, int b,int size);
void rendergame();
void rungame();
void runback();

   private:

SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;


};
#endif