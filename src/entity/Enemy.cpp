//
// Created by yorne-traumselle on 27/05/25.
//
#include "Enemy.h"
#include "Spells.h"
#include "Hero.h"

Enemy::Enemy(Map * map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense, Hero* hero): Fighter(map, position, size, filename, nameEntity, HP, MP, attack, defense), m_hero(hero) {
    m_fighterStatus = notInFight; // Enemies are not in fight by default
}



void Enemy::startTurn() {
    Fighter::startTurn();
    if (m_hero->getTile().calcDistance(m_tile) <= m_spells[0]->getMaxRange() ) {
        useSpell(m_hero->getTile(), 0);
        return;
    }
    else {
        Vector2<unsigned int> where = m_tile.findClosestReachableFreeCell(m_map->getMatriceBool(),
            m_hero->getTile(),
            m_MP[1]);
        setPosition(where)
    }
}

