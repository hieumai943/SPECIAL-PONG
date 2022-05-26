#include"menu.h"

void DRAW(const char*msg,int x, int y, int r, int g, int b ,int size){
  SDL_Surface *surf;
  SDL_Texture *tex;
  SDL_Renderer *renderer;
  TTF_Font *font= TTF_OpenFont("Peepo.ttf",size);
  SDL_Color color;
  color.r=r;
  color.g = g;
  color.b=b;
  color.a=255;
  SDL_Rect rect;
  surf= TTF_RenderText_Solid(font, msg, color);
  tex= SDL_CreateTextureFromSurface(renderer,surf);
  rect.x=x;
  rect.y=y;
  rect.w=surf-> w;
  rect.h= surf-> h;
  SDL_FreeSurface(surf);
  SDL_RenderCopy(renderer,tex,NULL, &rect);
  SDL_DestroyTexture(tex);

}