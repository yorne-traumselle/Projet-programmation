#ifndef __VICTORYUI_H__
#define __VICTORYUI_H__

#include "../utils/Vector2.h"

#include <SDL2/SDL_ttf.h>
#include <string>

class VictoryUI{
private:

    TTF_Font* m_font;

    SDL_Color m_textColor;
    SDL_Color m_buttonColor;
    SDL_Color m_buttonTextColor;

    Vector2<float> m_victoryPosition;
    Vector2<float> m_buttonPosition;
    Vector2<float> m_buttonSize;

    std::string m_message;
    std::string m_buttonLabel;

public:
    VictoryUI(TTF_Font * font);

    void setVictoryPosition(const Vector2<float>& pos);
    void setButtonPosition(const Vector2<float>& pos);
    void setButtonSize(const Vector2<float>& size);

    void render();
    bool handleClick(int mouseX, int mouseY);
};
#endif
