//
// Created by yorne-traumselle on 27/05/25.
//
#pragma once
#include "Fighter.h"

class Enemy : public Fighter {

public:
    Enemy(Map * map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense);
    ~Enemy() override = default;
    void update() override;
}
//ENEMY_H
