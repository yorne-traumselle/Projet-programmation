
#include "Entity.h"
#include "../graphics/Renderer.h"

Entity::Entity(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity):
    m_position(position), m_size(size), m_nameEntity(nameEntity){
        loadTexture(filename, m_nameEntity);
}

Entity::~Entity(){}

void Entity::setPosition(const Vector2<float>& position) {
    m_position = position;
}

const Vector2<float>& Entity::getPosition(){
    return m_position;
}

void Entity::loadTexture(const std::string &filename, const std::string &nameEntity) {
    m_nameEntity = nameEntity;
    m_texture = TextureManager::getInstance()->loadTexture(filename, m_nameEntity);
}

void Entity::render() {
    Renderer::getInstance()->drawTexture(m_texture.get(), m_position, Vector2<float>(m_texture->getWidth(), m_texture->getHeight()), 0.f);
}