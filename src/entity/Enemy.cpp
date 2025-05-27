//
// Created by yorne-traumselle on 27/05/25.
//
#include "Enemy.h"
#include "Spells.h"
Enemy::Enemy(Map * map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense): Fighter(map, position, size, filename, nameEntity, HP, MP, attack, defense) {
    m_fighterStatus = notInFight; // Enemies are not in fight by default

}