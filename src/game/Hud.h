#ifndef HUD_H
#define HUD_H

#include"/home/drtin/projet_info/Projet-programmation/src/graphics/Renderer.h"

class Hud{
private:
    int m_posX, m_posY;
    int m_width, m_height;


public:
    Hud( int x=10, int y = Renderer::getInstance() -> height(), int w=200, int h=100);
    void draw();


};



#endif 