#include "Hero.h"

Hero::Hero(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity):
    Entity(position, size, filename, nameEntity) {

}

Hero::~Hero() {}

void Hero::update() {

}

void Hero::render() {
    Entity::render();
}