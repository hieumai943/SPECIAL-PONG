#include"object.h"


int WIDTH= 1000;
int HEIGHT= 600;
double FONT_SIZE= 56;
double SIZE= 16;
double BALL_SPEED= 16;
double SPEED= 12;
double PI = 3.14;


SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;
SDL_Color color;
Object hnen,bgr,wall,wall1;
bool running;
int frameCount, timerFPS, lastFrame, fps;
SDL_Rect l_paddle, r_paddle, ball, score_board,tuong,tuong1;
double vX, vY;
string level1,level2,mode1,mode2;
string score,score0,score1,score2,score3;
int l_s, r_s;// diem trai va diem phai
bool turn ;
Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
int easy=0;


void serve(){// ham de giao bong
  

  if(turn) {
    ball.x=l_paddle.x+(l_paddle.w*4);//vi tri ban dau cua bong
    vX=BALL_SPEED/2;// van toc bong theo x
  } else {
    ball.x=r_paddle.x-(r_paddle.w*4);
    vX=-BALL_SPEED/2;
  }
  vY=0;
  ball.y=HEIGHT/2- SIZE/2;
  turn=!turn;// cu sau moi lan thua thi no quay nguoc bong lai
}
void write(string text, int x, int y){// ham nay de viet ti so ben tren
 SDL_Surface *surface;
 SDL_Texture *texture;
 const char*t = text.c_str();
 surface = TTF_RenderText_Solid(font, t, color);
 texture= SDL_CreateTextureFromSurface(renderer, surface);
 score_board.w=surface->w;
 score_board.h=surface->h;
 score_board.x=x-score_board.w;
 score_board.y=y-score_board.h;
 SDL_FreeSurface(surface);
 SDL_RenderCopy(renderer, texture, NULL, &score_board);
 SDL_DestroyTexture(texture);
}


void update(){

  score= "                   SCORE :          "+ to_string(l_s)+ "                  "+ to_string(r_s); 
  
  //2 ham o duoi nay de hoa cac paddle va bong co the dap nhau va phan lai
  if(SDL_HasIntersection(&ball, &r_paddle)) {
   Mix_PlayChannel(-1,gHigh,0);
  double kc = (r_paddle.y+(r_paddle.h/2))-(ball.y+(SIZE/2));// khoang cach tu tam bong den tam paddle
  double norm = kc/(r_paddle.h/2);
  double bounce = norm * (5*PI/12);
  vX=-BALL_SPEED*cos(bounce);
  vY=BALL_SPEED*-sin(bounce);
  
 }
 if(SDL_HasIntersection(&ball, &l_paddle)) {
   Mix_PlayChannel(-1,gHigh,0);
  double kc = (l_paddle.y+(l_paddle.h/2))-(ball.y+(SIZE/2));
  double norm = kc/(l_paddle.h/2);
  double bounce = norm * (5*PI/12);//75 do
  vX=BALL_SPEED*cos(bounce);
  vY=BALL_SPEED*-sin(bounce);
 }
 if(easy==2){
 if(SDL_HasIntersection(&tuong,&ball)||SDL_HasIntersection(&tuong1,&ball)){
   Mix_PlayChannel(-1,gHigh,0);
  
   double kc = (l_paddle.y+(l_paddle.h/2))-(ball.y+(SIZE/2));
  double norm = kc/(l_paddle.h/2);
  double bounce = norm * (5*PI/12);//75 do
  vX=BALL_SPEED*cos(bounce);
  vY=BALL_SPEED*-sin(bounce);
  
 }
 }
 // dieu khien AI 
  if(ball.y>r_paddle.y+r_paddle.h/2) r_paddle.y+=SPEED;
  if(ball.y<r_paddle.y+r_paddle.h/2) r_paddle.y-=SPEED;
  //tang diem so va quay về giữa khi bóng ra khỏi màn
    if(ball.y<=0||ball.y+SIZE>= HEIGHT) vY=-vY;
  
  if(ball.x<=0) {// tang diem
    r_s++;
    serve();

  }
    
  if(ball.x>=WIDTH-SIZE) {
    l_s++;
    serve();
  }

  // chan paddle
  if(l_paddle.y<0) l_paddle.y=0;
  if(l_paddle.y+l_paddle.h> HEIGHT) l_paddle.y= HEIGHT- l_paddle.h;
  if(r_paddle.y<0) r_paddle.y=0;
  if(r_paddle.y+r_paddle.h> HEIGHT) r_paddle.y= HEIGHT- r_paddle.h;
   ball.x+=vX;
   ball.y+=vY;
 

}


 
void inputmenu(){
  SDL_Event e;
  
const Uint8 *keystates= SDL_GetKeyboardState(NULL);
  while(SDL_PollEvent(&e)){

   if(e.type==SDL_MOUSEMOTION){
     int mouseX=e.motion.x;
     int mouseY=e.motion.y;
     stringstream ss;
     ss<<"X: "<< mouseX<<"Y:  "<< mouseY;
     SDL_SetWindowTitle(window,ss.str().c_str());

   }
    else if(e.type==SDL_MOUSEBUTTONDOWN){
     int mouseX=e.motion.x;
     int mouseY=e.motion.y;
 
      if(e.button.button==SDL_BUTTON_LEFT && mouseX>=80&& mouseX<=270 && mouseY>= 270 && mouseY<=330){
        level1=" EASY  ";
        level2=" HARD  ";
        score1=" ";
    }
   
    if( e.button.button== SDL_BUTTON_LEFT&& mouseX>=110&& mouseX<=270&&mouseY>=170&& mouseY<=225){
      easy=1;
    }
    if(e.button.button==SDL_BUTTON_LEFT && mouseX >= 101 && mouseX <= 273 && mouseY>= 371&& mouseY<=425 ){
      easy=2;
    }
     
   }
  }
   if(keystates[SDL_SCANCODE_ESCAPE]) running =0;
}
void inputgame(){
  SDL_Event e;
  const Uint8 *keystates= SDL_GetKeyboardState(NULL);
  while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT) running =0;
  }
  if(keystates[SDL_SCANCODE_ESCAPE]) running =0;
  if(keystates[SDL_SCANCODE_UP]) l_paddle.y-=SPEED;
  if(keystates[SDL_SCANCODE_DOWN]) l_paddle.y+=SPEED;
}
int  volume;
void setVolume(int v){
  volume=(MIX_MAX_VOLUME*v)/100;
}
void draw(Object o){
  SDL_Rect dest= o.getDest();
  SDL_Rect src= o.getSource();
  SDL_RenderCopyEx(renderer,o.getTex(),&src,&dest,0,NULL,SDL_FLIP_NONE);
}


void renderMenu(){


  SDL_RenderClear(renderer);//background
  
  hnen.setDest(0,0,1000,600);
  hnen.setSource(0,0,2000,1200);
  hnen.setImage("anhnen.jpg",renderer);

  draw(hnen);
  

   //bat dau tu duoi nay la set mau cua cac thanh phan
   SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,255);
    
   
   write(level1, WIDTH/2-215, FONT_SIZE*6-100);
   write(level2, WIDTH/2-215,FONT_SIZE*6+100);
   write(score1, WIDTH/2-215,FONT_SIZE*6);
   write(score2 , WIDTH/2 ,FONT_SIZE*6);
   write(score3, WIDTH/2+415 ,FONT_SIZE*6);
   

   SDL_RenderPresent(renderer);

}
void rendergame(){
  if(easy==1){
  
   SDL_RenderClear(renderer);//background
  draw(bgr);
  
   frameCount++;
  timerFPS= SDL_GetTicks()-lastFrame;
  if(timerFPS<(1000/60)){
      SDL_Delay((1000/60)-timerFPS);
  }
   SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,255);
   write(score, WIDTH/2+ FONT_SIZE*3,FONT_SIZE*2);
  SDL_RenderFillRect(renderer, &l_paddle);
   SDL_RenderFillRect(renderer, &r_paddle);
   SDL_RenderFillRect(renderer, &ball);



   SDL_RenderPresent(renderer);
}
if(easy==2){
   SDL_RenderClear(renderer);//background
  draw(bgr);
  draw(wall);
  draw(wall1);
   frameCount++;
  timerFPS= SDL_GetTicks()-lastFrame;
  if(timerFPS<(1000/60)){
      SDL_Delay((1000/60)-timerFPS);
  }
   SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,255);
   write(score, WIDTH/2+ FONT_SIZE*3,FONT_SIZE*2);
  SDL_RenderFillRect(renderer, &l_paddle);
   SDL_RenderFillRect(renderer, &r_paddle);
   SDL_RenderFillRect(renderer, &ball);

   SDL_RenderPresent(renderer);
}
}

void close(){

  Mix_FreeChunk(gHigh);
  gHigh=NULL;

  Mix_FreeMusic(gnhacnen);
  gnhacnen=NULL;
  Mix_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(font);
  
  SDL_Quit();
}
int main(int argc, char* args[]){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) cout << "Failed at SDL_Init()" << endl;
  if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) cout << "Failed at SDL_CreateWindowAndRenderer())" << endl;
 
  
 	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
   
      gnhacnen = Mix_LoadMUS("nhacnen.mp3");
         gHigh =Mix_LoadWAV("low.wav");
    if(Mix_PlayingMusic()==0) Mix_PlayMusic(gnhacnen,-1);
  else{
    if(Mix_PausedMusic()==1) Mix_ResumeMusic();
    else Mix_PauseMusic();
  }
  
   
    TTF_Init();
    font = TTF_OpenFont("Peepo.ttf",FONT_SIZE);
    bgr.setDest(0,0,1000,600);
  bgr.setSource(0,0,2000,1200);
  bgr.setImage("bgr.bmp",renderer);

  wall.setDest(300,300,70,100);
  wall.setSource(0,0,1000,1200);
  wall.setImage("cauthu.png",renderer);
  
  wall1.setDest(650,190,70,100);
  wall1.setSource(0,0,1000,1200);
  wall1.setImage("cauthu0.png",renderer);
  
    running =1;
    int lastTime=0;
    level1=" ",level2=" ",mode1=" ",mode2=" ";
    score1="  LEVEL  ";
    score2="  MODE ";
    score3="  PLAY ";
   
    color.r= 255;
    color.g=255;
    color.b=255;
    
  l_s = r_s =0;
  l_paddle.x= 32; l_paddle.h=HEIGHT/5;
  l_paddle.y =(HEIGHT/2)-(l_paddle.h/2);
  l_paddle.w= 12;
  r_paddle = l_paddle;
  r_paddle.x = WIDTH - r_paddle.w-32;
  tuong.x=320,tuong.y=310;
  tuong.w=43,tuong.h=85;
  tuong1.x= 660, tuong1.y=195;
  tuong1.w=43,tuong1.h=85;
  ball.w=ball.h=SIZE;
  
  
   
   serve();
  
   while(running){
     renderMenu();
      
     inputmenu();
     if(easy==1|| easy==2) running=0;
   }
  
 running =1;
  
    while (running){
 
        lastFrame =SDL_GetTicks();
        if(lastFrame>=(lastTime+1000)){
            lastTime=lastFrame;
            fps=frameCount;
            frameCount=0;
        }
         update();
      
       inputgame();
        // khởi tạo thời gian chạy cho gậy, vẽ màu
        
       rendergame();
    
    }
  
    close();
 

}