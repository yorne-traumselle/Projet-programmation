#include "Hero.h"

#include "inventory/item/Consumable.h"
#include "inventory/item/Equipment.h"

Hero::Hero(Map* map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense, Inventory * inventory):Fighter(map,position, size, filename, nameEntity,HP,MP, attack, defense), m_inventory(inventory), m_level(1) {}

Hero::~Hero() {}

void Hero::update() {
    Fighter::update();
}

void Hero::render() {
    Entity::render();
}

void Hero::gainLevel() {
    m_level++;
}

void Hero::useItem(const std::string& itemName) {
    if (m_inventory->hasItem(itemName)) {
        std::shared_ptr<Item> item = m_inventory->getItem(itemName);
        if (Consumable* consumable = dynamic_cast<Consumable*>(item.get())) {
            // consumable is a pointer to Consumable
            consumable->consume(*this);
            m_inventory->removeItem(itemName);
        }
        if (Equipment * equipment = dynamic_cast<Equipment*>(item.get())) {
            equipment->equipped(*this);
            m_inventory->removeItem(itemName);
        }
    }
}

