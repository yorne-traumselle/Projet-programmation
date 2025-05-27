#ifndef __GAMEOVERUI_H__
#define __GAMEOVERUI_H__

#include "../utils/Vector2.h"
#include "../graphics/Renderer.h"

#include <SDL2/SDL_ttf.h>
#include <string>

class GameOverUI{
private:

    TTF_Font* m_font;

    SDL_Color m_textColor;
    SDL_Color m_buttonColor;
    SDL_Color m_buttonTextColor;

    Vector2<float> m_gameOverPosition;
    Vector2<float> m_buttonPosition;
    Vector2<float> m_buttonSize;

    std::string m_message;
    std::string m_buttonLabel;

public:
    GameOverUI(TTF_Font * font);

    void setGameOverPosition(const Vector2<float>& pos);
    void setButtonPosition(const Vector2<float>& pos);
    void setButtonSize(const Vector2<float>& size);

    void render();
    bool handleClick(int mouseX, int mouseY);
};
#endif
