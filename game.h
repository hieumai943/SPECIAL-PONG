#ifndef GAME_H
#define GAME_H


#include"object.h"
#include"menu.h"


const double SIZE= 23;
const double BALL_SPEED= 16;
const double SPEED = 12;
const double PI = 3.14;



class Game{
   public:
Game();
~Game();
SDL_Color color;

bool running;


SDL_Rect l_paddle, r_paddle, ball ,tuong,tuong1;

SDL_Rect score_board;

int frameCount, timerFPS, lastFrame, fps;
Object bgr,bgrMenu,wall,wall1,m_ball;
double vX, vY;
string score,level1,level2,score1,mode1,mode2,score2,score3;
int lastTime=0;
int l_s, r_s;// diem trai va diem phai
bool turn ;
Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
int easy,mode;

void init();
void variable();
void serve();
void draw(Object o);
void DRAW(const char*msg,int x, int y, int r, int g, int b ,int size);
void inputMenu();
void renderMenu();
void runMenu();
void update();
void inputgame();
void write(string text, int x, int y,int r, int g, int b);
void rendergame();
void rungame();
void close();
  

   private:

SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;


};
#endif