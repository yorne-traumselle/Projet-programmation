#include "InventoryUI.h"

InventoryUI::InventoryUI(Inventory& inventory, TTF_Font* font):
	m_inventory(inventory), m_font(font), m_selectedIndex(0),
	m_textColor{255, 255, 255, 255}, m_position(50, 50),
    m_itemSpacing(0, 40), m_itemBoxSize(200, 30){
    update();
}

void InventoryUI::update(){
    m_itemNames.clear();
    for (const auto& pair : m_inventory.m_items) {
        m_itemNames.push_back(pair.first);
    }
}

void InventoryUI::handleInput(const SDL_Event& event){
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_DOWN) {
            m_selectedIndex = (m_selectedIndex + 1) % m_itemNames.size();
        } else if (event.key.keysym.sym == SDLK_UP) {
            m_selectedIndex = (m_selectedIndex - 1 + m_itemNames.size()) % m_itemNames.size();
        }
    }
    if (event.type == SDL_MOUSEBUTTONDOWN){
        int x, y;
        SDL_GetMouseState(&x, &y);
        for (int i = 0; i < m_itemNames.size(); ++i) {
            Vector2<float> itemPos = m_position + m_itemSpacing * i;
            SDL_Rect box = { (int)itemPos[0], (int)itemPos[1], (int)m_itemBoxSize[0], (int)m_itemBoxSize[1] };
            if (x >= box.x && x <= box.x + box.w && y >= box.y && y <= box.y + box.h) {
                m_selectedIndex = i;
            }
        }
    }
}

void InventoryUI::render(Renderer* renderer){
    for (size_t i = 0; i < m_itemNames.size(); ++i) {
        Vector2<float> pos = m_position + m_itemSpacing * i;

        // Highlight selected item
        if ((int)i == m_selectedIndex) {
            SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 100, 100, 255, 150);
            SDL_Rect highlight = { (int)pos[0], (int)pos[1], (int)m_itemBoxSize[0], (int)m_itemBoxSize[1] };
            SDL_RenderFillRect(renderer->getSdlRenderer(), &highlight);
        }

        std::shared_ptr<Item> item = m_inventory.getItem(m_itemNames[i]);
        int quantity = item ? m_inventory.m_items[m_itemNames[i]].second : 0;
        std::string displayText = m_itemNames[i] + " x" + std::to_string(quantity);
        renderer->drawString(displayText, pos, m_font, m_textColor, 1.0);
    }

    std::string goldText = "Gold: " + std::to_string(m_inventory.getGold());
    renderer->drawString(goldText, Vector2<float>(m_position[0], m_position[1] + m_itemSpacing[1] * m_itemNames.size() + 20), m_font, m_textColor, 1.0);
}

void InventoryUI::setPosition(const Vector2<float>& pos){
    m_position = pos;
}
