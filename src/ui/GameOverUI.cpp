#include "GameOverUI.h"

GameOverUI::GameOverUI(TTF_Font* font):
	m_font(font), m_textColor{255, 0, 0, 255}, m_buttonColor{50, 50, 50, 255}, m_buttonTextColor{255, 255, 255, 255},
	m_gameOverPosition(Vector2<float>(400, 200)), m_buttonPosition(Vector2<float>(100, 40)), m_buttonSize(200, 30),  m_message("Game Over"), m_buttonLabel("Retry !"){
}

void GameOverUI::setGameOverPosition(const Vector2<float>& pos){
	m_gameOverPosition = pos;
}

void GameOverUI::setButtonPosition(const Vector2<float>& pos){
	m_buttonPosition = pos;
}

void GameOverUI::setButtonSize(const Vector2<float>& size){
	m_buttonSize = size;
}

void GameOverUI::render() {
    Renderer* renderer = Renderer::getInstance();

    // Ici, on affiche le texte "Game Over"
    int textW, textH;
    TTF_SizeText(m_font, m_message.c_str(), &textW, &textH);
    Vector2<float> centeredText = m_gameOverPosition - Vector2<float>(textW / 2, textH / 2);
    renderer->drawString(m_message, centeredText, m_font, m_textColor, 1.0);

    // Affichage du bouton "Recommencer"
    SDL_Rect buttonRect = {
        static_cast<int>(m_buttonPosition[0]),
        static_cast<int>(m_buttonPosition[1]),
        static_cast<int>(m_buttonSize[0]),
        static_cast<int>(m_buttonSize[1])
    };
    renderer->drawRect(buttonRect, m_buttonColor, true);

    // Centrer le texte dans le bouton
    TTF_SizeText(m_font, m_buttonLabel.c_str(), &textW, &textH);
    Vector2<float> buttonTextPos = m_buttonPosition + (m_buttonSize - Vector2<float>(textW, textH)) / 2;
    renderer->drawString(m_buttonLabel, buttonTextPos, m_font, m_buttonTextColor, 1.0);
}

bool GameOverUI::handleClick(int mouseX, int mouseY) {
    return mouseX >= m_buttonPosition[0] && mouseX <= m_buttonPosition[0] + m_buttonSize[0] && mouseY >= m_buttonPosition[1] && mouseY <= m_buttonPosition[1] + m_buttonSize[1];
}
