/*
il faut avoir une case rectangle qui contient: 
en haut à gauche : bare de vie du héro
    bottom: la bare de mouvement point ( combien de celle il en reste psk il y a un nombre limité de celle possible dispo dans fighter)
en haut à droite: bare de vie d'ennmi (si y a 2 enmis ..les bares sotn above/bottom disponibles dans fighter )
en bas à gauche: la listes des compét (disponibles dans fighter) */


#ifndef __COMBATUI__H__
#define __COMBATUI__H__

#include "../entity/Fighter.h"
#include "../graphics/Renderer.h"
#include <memory>
#include <vector>

class CombatUI {
private:
    std::shared_ptr<Fighter> m_hero;
    std::vector<std::shared_ptr<Fighter>> m_enemies;
    std::vector<SDL_Rect> m_spellButtons;   
    int m_selectedSpellIndex = -1;


public:
    CombatUI(std::shared_ptr<Fighter> hero, const std::vector<std::shared_ptr<Fighter>>& enemies);
    ~CombatUI();

    void render (Renderer * renderer, TTF_Font * font);

    void renderHero(Renderer * renderer, TTF_Font* font);
    void renderEnemies(Renderer * renderer, TTF_Font* font);

    void renderSpells(Renderer * renderer, TTF_Font* font);

    bool handleClick(int mouseX, int mouseY);

};
#endif
