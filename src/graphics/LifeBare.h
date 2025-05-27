#ifndef LIFEBAR_H
#define LIFEBAR_H
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include "/home/drtin/projet_info/Projet-programmation/src/utils/Vector2.h"

class LifeBar {
private:
    Vector2<float> m_position;
    Vector2<float> m_size;
    int m_maxHP; //c'est le Health Point Max: nb e vie max (je conseille de ne pas les dép à jouer mais à profiter!!)
    int m_currentHP; 
    SDL_Color m_bcak;
    SDL_Color m_fg;

public:
    LifeBar (Vector2<float> position, Vector2 <float> size, int maxHP);
    void setHP (int hp);
    void render (SDL_Renderer* render) const; // ici on va afficher la barre de vie
    void setColor(SDL_Color back, SDL_Color fg);

};




#endif