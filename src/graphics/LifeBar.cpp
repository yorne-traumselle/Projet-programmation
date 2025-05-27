// #include "LifeBare.h"

// LifeBar::LifeBar(Vector2<float> position, Vector2 <float> size, int maxHP): 
//     m_position(position),
//     m_size(size),
//     m_maxHP(maxHP),
//     m_currentHP(maxHP) {
//         m_bcak={50,50,50,255}; //gris foncé 
//         m_fg = {200,0,0,255}; //red like blood!!!


//     }

// void LifeBar::setHP(int hp){
//     if(hp<0 ){
//         m_currentHP= 0; // t'es déjà mort cheh!
//     }
//     if(hp> m_maxHP){
//         m_currentHP=m_maxHP;
//     }
// void LifeBar::render(SDL_Renderer* renderer) const {
//     // Calcul du ratio de vie
//     float ratio = static_cast<float>(m_currentHP) / m_maxHP;
//     int filledWidth = static_cast<int>(m_size[0] * ratio);

//     SDL_Rect bgRect = { static_cast<int>(m_position[0]), static_cast<int>(m_position[1]),
//                         static_cast<int>(m_size[0]), static_cast<int>(m_size[1]) };

//     SDL_Rect fgRect = { static_cast<int>(m_position[0]), static_cast<int>(m_position[1]),
//                         filledWidth, static_cast<int>(m_size[1]) };

//     // Fond
//     SDL_SetRenderDrawColor(renderer, m_bgColor.r, m_bgColor.g, m_bgColor.b, m_bgColor.a);
//     SDL_RenderFillRect(renderer, &bgRect);

//     // Vie restante
//     SDL_SetRenderDrawColor(renderer, m_fgColor.r, m_fgColor.g, m_fgColor.b, m_fgColor.a);
//     SDL_RenderFillRect(renderer, &fgRect);
// }
// }