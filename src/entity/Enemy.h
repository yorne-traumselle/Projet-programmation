//
// Created by yorne-traumselle on 27/05/25.
//
#pragma once
#include "Fighter.h"
class Hero;
class Enemy : public Fighter {

    Hero* m_hero;

public:
    Enemy(Map * map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense, Hero* hero);
    ~Enemy() override = default;


    void startTurn() override;
};
//ENEMY_H
