#include "CombatUI.h"

CombatUI::CombatUI(std::shared_ptr<Fighter> hero, const std::vector<std::shared_ptr<Fighter>>& enemies) : m_hero(hero), m_enemies(enemies){};
CombatUI::~CombatUI(){}

void CombatUI::render(Renderer * renderer, TTF_Font* font){
    renderHero(renderer, font);
    renderEnemies(renderer, font);
    renderSpells(renderer, font);
}

void CombatUI::renderHero(Renderer * renderer,  TTF_Font* font){
    SDL_Rect heroRect = {20,20,300, 150};
    renderer->Renderer::drawRect(heroRect, {50,50,50,200}, false);

    //bare de vie
    int barW=200;
    int barH= 20;
    float healthRatio = (float)m_hero->getHP() / m_hero->getMaxHP();
    SDL_Rect healthBarBack = {heroRect.x + 10, heroRect.y + 10, barW, barH};
    SDL_Rect healthBarFront = {heroRect.x + 10, heroRect.y + 10, static_cast<int>(barW * healthRatio), barH};
    renderer->Renderer::drawRect(healthBarBack, {100, 0, 0, 255});
    renderer->Renderer::drawRect(healthBarFront, {255, 0, 0, 255});
    std::string healthText = "HP: " + std::to_string(m_hero->getHP()) + "/" + std::to_string(m_hero->getMaxHP());
    renderer->Renderer::drawString(healthText.c_str(),  Vector2<float>(heroRect.x + 15, heroRect.y + 12), font, {255, 255, 255, 255}, 1.0);   

    
    //bare de point de mouvement 
    std::string movemetText = "MP: " + std::to_string(m_hero->getMP());
    renderer ->Renderer::drawString(movemetText.c_str(),Vector2<float>(heroRect.x + 15, heroRect.y + 40), font, {255, 255, 255, 255}, 1.0);

}

void CombatUI::renderEnemies(Renderer* renderer, TTF_Font* font) {
    int startX = 600;
    int startY = 20;
    int width = 300;
    int height = 150;
    int spacing = 40;
    int barWidth = 200;
    int barHeight = 20;

    SDL_Rect enemiesRect = {startX, startY, width, height};
    renderer->Renderer::drawRect(enemiesRect, {80, 80, 80, 200}, false);

    for (size_t i = 0; i < m_enemies.size(); ++i) {
        auto enemy = m_enemies[i];
        float healthRatio = static_cast<float>(enemy->getHP()) / enemy->getMaxHP();

        SDL_Rect backgroundBar = {
            startX + 10,
            startY + 10 + static_cast<int>(i) * spacing,
            barWidth,
            barHeight
        };

        SDL_Rect foregroundBar = {
            startX + 10,
            startY + 10 + static_cast<int>(i) * spacing,
            static_cast<int>(barWidth * healthRatio),
            barHeight
        };

        renderer->Renderer::drawRect(backgroundBar, {100, 0, 0, 255});

        renderer->Renderer::drawRect(foregroundBar, {255, 0, 0, 255});
    }
}


void CombatUI::renderSpells(Renderer* renderer, TTF_Font* font) {
    int startX = 20;
    int startY = 200;
    int width = 300;
    int height = 200;
    int spacing = 30;

    SDL_Rect spellRect = {startX, startY, width, height};
    renderer->Renderer::drawRect(spellRect, {60, 60, 60, 200}, false);

    auto spells = m_hero->getSpells();

    m_spellButtons.clear();  

    for (size_t i = 0; i < spells.size(); ++i) {
        std::string spellName = spells[i]->getType();

        // Création du rectangle pour cliquer
        SDL_Rect buttonRect = {startX + 10, startY + 10 + static_cast<int>(i * spacing), 200, 25};
        m_spellButtons.push_back(buttonRect); 

        // Couleur différente si ce sort est sélectionné
        SDL_Color textColor = (i == m_selectedSpellIndex) ? SDL_Color{255, 255, 0, 255} : SDL_Color{255, 255, 255, 255};
        SDL_Color bgColor = {100, 100, 100, 255};

        // Dessin du bouton + nom du sort
        renderer->Renderer::drawRect(buttonRect, bgColor);
        renderer->Renderer::drawString(spellName.c_str(), Vector2<float>(buttonRect.x + 5, buttonRect.y + 5), font, textColor, 1.0);
    }
}
