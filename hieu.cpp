#include"object.h"
#include"menu.h"
#include"game.h"
SDL_Renderer *renderer;
SDL_Window *window;
TTF_Font* font;
Mix_Music *gnhacnen = NULL;
Mix_Chunk *gHigh=NULL;
Object hnen,bgr,wall,wall1;

bool running;
int frameCount, timerFPS, lastFrame, fps;
int lastTime=0;
int easy;
void inputgame(){
  SDL_Event e;
  const Uint8 *keystates= SDL_GetKeyboardState(NULL);
  while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT) running =0;
  }
  if(keystates[SDL_SCANCODE_ESCAPE]) running =0;
  
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


   SDL_RenderPresent(renderer);
  }
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
    while (running){
 
        lastFrame =SDL_GetTicks();
        if(lastFrame>=(lastTime+1000)){
            lastTime=lastFrame;
            fps=frameCount;
            frameCount=0;
        }
        
      
       inputgame();
        // khởi tạo thời gian chạy cho gậy, vẽ màu
     easy=1;
     rendergame();
    
    }



}