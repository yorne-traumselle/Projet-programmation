#include "CombatUI.h"

CombatUI::CombatUI(std::shared_ptr<Fighter> hero,
                   const std::vector<std::shared_ptr<Fighter>>& enemies)
    : m_hero(std::move(hero)), m_enemies(enemies) {}

CombatUI::~CombatUI() = default;

void CombatUI::render(Renderer* renderer, TTF_Font* font) {
    renderHero(renderer, font);
    renderEnemies(renderer, font);
    renderSpells(renderer, font);
}

void CombatUI::renderHero(Renderer* renderer, TTF_Font* font) {
    // Cadre du héros
    SDL_Rect heroRect = {20, 20, 300, 150};
    renderer->drawRect(heroRect, {50, 50, 50, 200}, false);

    // Barre de vie
    int barW = 200, barH = 20;
    float hpRatio = float(m_hero->getHP()) / m_hero->getMaxHP();
    SDL_Rect backHP {heroRect.x + 10, heroRect.y + 10, barW, barH};
    SDL_Rect frontHP {heroRect.x + 10, heroRect.y + 10,
                      int(barW * hpRatio), barH};
    renderer->drawRect(backHP,   {100, 0, 0,   255}, true);
    renderer->drawRect(frontHP,  {255, 0, 0,   255}, true);

    std::string hpText = "HP: " + std::to_string(m_hero->getHP())
                       + "/" + std::to_string(m_hero->getMaxHP());
    renderer->drawString(hpText,
                         Vector2<float>(heroRect.x + 15, heroRect.y + 12),
                         font, {255,255,255,255});

    // MP
    std::string mpText = "MP: " + std::to_string(m_hero->getMP());
    renderer->drawString(mpText,
                         Vector2<float>(heroRect.x + 15, heroRect.y + 40),
                         font, {255,255,255,255});
}

void CombatUI::renderEnemies(Renderer* renderer, TTF_Font* font) {
    int startX = 600, startY = 20;
    int barW = 200, barH = 20, spacing = 40;

    // Fond cadre
    SDL_Rect enemyBox {startX, startY, 300, int(m_enemies.size()) * spacing + 20};
    renderer->drawRect(enemyBox, {80,80,80,200}, false);

    for (size_t i = 0; i < m_enemies.size(); ++i) {
        auto& e = m_enemies[i];
        float ratio = float(e->getHP()) / e->getMaxHP();
        SDL_Rect back {startX + 10, startY + 10 + int(i)*spacing, barW, barH};
        SDL_Rect front{startX + 10, startY + 10 + int(i)*spacing,
                       int(barW * ratio), barH};

        renderer->drawRect(back,  {100,0,0,255}, true);
        renderer->drawRect(front, {255,0,0,255}, true);
    }
}

void CombatUI::renderSpells(Renderer* renderer, TTF_Font* font) {
    int startX = 20, startY = 200;
    int width = 300, height = 200, spacing = 30;

    // Cadre des sorts
    SDL_Rect spellsBox {startX, startY, width, height};
    renderer->drawRect(spellsBox, {60,60,60,200}, false);

    auto spells = m_hero->getSpells();
    m_spellButtons.clear();

    for (size_t i = 0; i < spells.size(); ++i) {
        SDL_Rect btn { startX + 10,
                       startY + 10 + int(i)*spacing,
                       200, 25 };
        m_spellButtons.push_back(btn);

        // Background
        SDL_Color bg = (int(i) == m_selectedSpellIndex)
                       ? SDL_Color{100,100,150,200}
                       : SDL_Color{100,100,100,200};
        renderer->drawRect(btn, bg, true);

        // Texte du sort
        std::string name = spells[i]->getType();
        renderer->drawString(name,
                             Vector2<float>(btn.x + 5, btn.y + 5),
                             font,
                             {255,255,255,255});
    }
}

bool CombatUI::handleClick(int mouseX, int mouseY) {
    for (size_t i = 0; i < m_spellButtons.size(); ++i) {
        auto& rect = m_spellButtons[i];
        if (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
            mouseY >= rect.y && mouseY <= rect.y + rect.h) {
            m_selectedSpellIndex = int(i);
            // Lancement du sort sur le premier ennemi
            if (!m_enemies.empty()) {
                auto spell = m_hero->getSpells()[i];
                spell->cast(*m_hero, m_enemies[0]->getPosition(), *m_hero->getMap());
            }
            return true;
        }
    }
    return false;
}
