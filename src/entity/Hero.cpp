#include "Hero.h"

#include "Spells.h"
#include "inventory/item/Consumable.h"
#include "inventory/item/Equipment.h"

Hero::Hero(Map* map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense, Inventory * inventory):Fighter(map,position, size, filename, nameEntity,HP,MP, attack, defense), m_inventory(inventory), m_level(1) {
    m_fighterStatus = notInFight; // Heroes are not in fight by default
    m_utilized = false; // Not utilized any item at the start of the turn
    addSpell(new DamageSpell(5, Spell::classic, Spell::mono, 1, 5, 0));
    addSpell(new HealSpell(5, Spell::classic, Spell::mono, 1, 5, 0));
    addSpell(new TeleportSpell(5, Spell::classic, 5, 0));
}

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
    if (m_utilized || m_status!= not_moving) {
        return; // already used an item this turn
    }
    if (m_inventory->hasItem(itemName)) {
        std::shared_ptr<Item> item = m_inventory->getItem(itemName);
        if (Consumable* consumable = dynamic_cast<Consumable*>(item.get())) {
            // consumable is a pointer to Consumable
            consumable->consume(*this);
            m_inventory->removeItem(itemName);
            m_utilized = true;
        }
        if (Equipment * equipment = dynamic_cast<Equipment*>(item.get())) {
            equipment->equipped(*this);
            m_inventory->removeItem(itemName);
            m_utilized = true;
        }
    }
}

void Hero::startTurn() {
    Fighter::startTurn();
    m_utilized= false;
}
