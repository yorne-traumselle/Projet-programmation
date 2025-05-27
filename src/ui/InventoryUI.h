#ifndef __INVENTORYUI_H__
#define __INVENTORYUI_H__

#include "../inventory/Inventory.h"
#include "../graphics/Renderer.h"
#include "../graphics/Texture.h"
#include "../utils/Vector2.h"

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class InventoryUI {
private:
    Inventory& m_inventory;

    TTF_Font* m_font;

    SDL_Color m_textColor;

    // Un vecteur qui sert de cache pour les noms des items, vu que sinon il faut faire des for
    std::vector<std::string> m_itemNames;

    // indice pour dire sur quel item on est (mis à jour quand on change)
    int m_selectedIndex;

    // Pour l'affichage
    Vector2<float> m_position;
    Vector2<float> m_itemSpacing;
    Vector2<float> m_itemBoxSize;

public:
    // Constructeur
    InventoryUI(Inventory& inventory, TTF_Font* font);

    // Permet d'actualiser la liste des items si besoin
    void update();

    // Permet de gérer la navigation
    void handleInput(const SDL_Event& event);

    // Permet d'afficher le menu
    void render(Renderer* renderer);

    // Permet de set la position du curseur (quel item est actuellement sélectionné)
    void setPosition(const Vector2<float>& pos);
};
#endif
