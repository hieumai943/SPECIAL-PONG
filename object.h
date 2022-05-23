#ifndef OBJECT_H
#define OBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include <bits/stdc++.h>
#include <math.h>
#include<SDL2/SDL_mixer.h>
#include<string>

using namespace std;

class Object{
    private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture *tex;
    public:
    SDL_Rect getDest() const{return dest;}
    SDL_Rect getSource() const{return src;}
    void setDest(int x, int y, int w ,int h);
     void setSource (int x,int y, int w ,int h);
    void setImage(string filename ,SDL_Renderer* renderer);
    SDL_Texture* getTex() const {return tex;}
};


#endif