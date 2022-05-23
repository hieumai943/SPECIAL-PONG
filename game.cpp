#include"game.h"

void Game::init(){


  bgr.setDest(0,0,1000,600);
  bgr.setSource(0,0,2000,1200);
  bgr.setImage("anhnen.jpg",renderer);
  draw(bgr);
  wall.setDest(300,300,70,100);
  wall.setSource(0,0,1000,1200);
  wall.setImage("cauthu.png",renderer);
  
  wall1.setDest(650,190,70,100);
  wall1.setSource(0,0,1000,1200);
  wall1.setImage("cauthu0.png",renderer);
}
void Game:: variable(){
     
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

}
void Game:: serve(){// ham de giao bong
  
  
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

void Game:: update(){

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
 if(menu.easy==2){
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


void Game:: inputgame(){
  SDL_Event e;
  const Uint8 *keystates= SDL_GetKeyboardState(NULL);
  
  while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT) running =0;
  }
  if(keystates[SDL_SCANCODE_ESCAPE]) running =0;
  if(keystates[SDL_SCANCODE_UP]) l_paddle.y-=SPEED;
  if(keystates[SDL_SCANCODE_DOWN]) l_paddle.y+=SPEED;
}
void Game::draw(Object o){
   SDL_Rect dest= o.getDest();
  SDL_Rect src= o.getSource();
  SDL_RenderCopyEx(renderer,o.getTex(),&src,&dest,0,NULL,SDL_FLIP_NONE);
}

void Game:: rendergame(){
  

  if(menu.easy==1){
  
   SDL_RenderClear(renderer);//background

  draw(bgr);

   frameCount++;
  timerFPS= SDL_GetTicks()-lastFrame;
  if(timerFPS<(1000/60)){
      SDL_Delay((1000/60)-timerFPS);
  }
   SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,255);
 
  SDL_RenderFillRect(renderer, &l_paddle);
   SDL_RenderFillRect(renderer, &r_paddle);
   SDL_RenderFillRect(renderer, &ball);

   SDL_RenderPresent(renderer);
  }
if(menu.easy==2){
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
   menu.write(score, WIDTH/2+ FONT_SIZE*3,FONT_SIZE*2);
  SDL_RenderFillRect(renderer, &l_paddle);
   SDL_RenderFillRect(renderer, &r_paddle);
   SDL_RenderFillRect(renderer, &ball);

   SDL_RenderPresent(renderer);
}
}
void Game:: rungame(){
  running=1;

  while(running){
    
        lastFrame =SDL_GetTicks();
        if(lastFrame>=(lastTime+1000)){
            lastTime=lastFrame;
            fps=frameCount;
            frameCount=0;
        }
        update();
        inputgame();
        rendergame();
  }
}
void Game:: close(){

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