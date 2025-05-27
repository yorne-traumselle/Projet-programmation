#include "Hud.h"

Hud::Hud(int x, int y, int w, int h)
    : m_posX(x), m_posY(y), m_width(w), m_height(h)
{}

void Hud::draw()
{
    SDL_Rect rect = { m_posX, m_posY, m_width, m_height };

   Renderer::getInstance()->setDrawColor(50, 50, 50, 200);
    SDL_RenderFillRect(Renderer::getInstance()->getSdlRenderer(), &rect);

     // Contour blanc
    Renderer::getInstance()->setDrawColor(255, 255, 255, 255);
    SDL_RenderDrawRect(Renderer::getInstance()->getSdlRenderer(), &rect);
}
