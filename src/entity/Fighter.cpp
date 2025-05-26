//
// Created by yorne-traumselle on 26/05/25.
//
#include "Fighter.h"

Fighter::Fighter(Map * map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense): Entity(map,position, size, filename, nameEntity), m_maxHP(HP), m_HP(HP), m_defense(defense), m_fighterStatus(notInFight) {
    m_MP[0]= MP;
    m_MP[1]= MP;
    m_attack[0] = attack;
    m_attack[1] = attack;
    m_defense[0] = defense;
    m_defense[1] = defense;
}

void Fighter::setPosition(const Vector2<unsigned int>& position) {
    if (m_fighterStatus == notInFight) {
        Entity::setPosition(position);
    }
    else {
        int distance = distance(m_tile, position);
        if (distance > m_MP[1]) {
            Entity::setPosition(position);
        }

    }
}

unsigned int Fighter::distance(const Vector2<unsigned int>& v1, const Vector2<unsigned int>& v2) {
    return std::abs(static_cast<int>(v1[0]) - static_cast<int>(v2[0])) + std::abs(static_cast<int>(v1[1]) - static_cast<int>(v2[0]));
}


void Fighter::takeDamage(int damage) {
    m_HP -= damage;
    if (m_HP < 0) {
        m_HP = 0;
    }
}

void Fighter::getHealed(int heal) {
    m_HP += heal;
    if (m_HP > m_maxHP) {
        m_HP = m_maxHP;
    }
}

unsigned int Fighter::getHP() const {
    return m_HP;
}



void Fighter::gainDef(int def, bool inFight) {
    if (!inFight) {
        m_defense[0] += def;
    }
    m_defense[1] += def;
    m_defense[0] = std::min(m_defense[0], 100);
    m_defense[1] = std::min(m_defense[1], 100);
    m_defense[0] = std::max(m_defense[0], 0);
    m_defense[1] = std::max(m_defense[1], 0);
}

void Fighter::gainMP(int mp, bool inFight) {
    if (!inFight) {
        m_MP[0] += mp;
    }
    m_MP[1] += mp;
    m_MP[0] = std::max(m_MP[0], 0);
    m_MP[1] = std::max(m_MP[1], 0);
}

void Fighter::gainAttack(int attack, bool inFight) {
    if (!inFight) {
        m_attack[0] += attack;
    }
    m_attack[1]+= attack;
    m_attack[0] = std::max(m_attack[0], 0);
    m_attack[1] = std::max(m_attack[1], 0);
}

void Fighter::update() {
    Entity::update();
    if (m_HP==0) {
        m_status = destroy;
    }
}

unsigned int Fighter::getAttack() const{
    return m_attack[1];
}

unsigned int Fighter::getDefense() const{
    return m_defense[1];
}