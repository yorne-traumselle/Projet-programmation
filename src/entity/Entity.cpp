
#include "Entity.h"
#include "../graphics/Renderer.h"
#include "../config.h"

Entity::Entity(Map* map, const Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, float speed): m_map(map),
    m_position((position +Vector2(0.5, 0.5))* JeuESIR::originalTileHeight), m_tile(position), m_speed(speed), m_size(size), m_nameEntity(nameEntity), m_status(not_moving), m_way(Map::Way()){
        loadTexture(filename, m_nameEntity);
}

Entity::~Entity(){}

void Entity::setPosition(const Vector2<unsigned int>& position) {
    if (!m_map->getCell(position)->occupied()) {
        Map::Way way = Map::Way(m_map->getCell(m_tile), m_map->getCell(position));
        m_tile = position;
        m_status = running;
    }
}
void Entity::setPositionDirectly(const Vector2<unsigned int>& position) {
    m_tile = position;
    m_position = (position +Vector2(0.5, 0.5))* JeuESIR::originalTileHeight;
}

const Vector2<float>& Entity::getPosition() const {
    return m_position;
}

const Vector2<unsigned int>& Entity::getTile() const {
    return m_tile;
}

void Entity::loadTexture(const std::string &filename, const std::string &nameEntity) {
    m_nameEntity = nameEntity;
    m_texture = TextureManager::getInstance()->loadTexture(filename, m_nameEntity);
}

void Entity::render() {
    Renderer::getInstance()->drawTexture(m_texture.get(), m_position, Vector2<float>(m_texture->getWidth(), m_texture->getHeight()), 0.f);
}

void Entity::setTile(const Vector2<unsigned int>& tile) {
    m_tile = tile;
}

void Entity::update() {
    render();
    if (m_status == running){
        Vector2<float> target = (m_tile + m_way.front() + Vector2<float>(0.5, 0.5))*JeuESIR::originalTileHeight;
        Vector2<float> difference = target-m_position;
        float distance = difference.norm();
        Vector2<float> direction = difference/distance;
        if (distance < m_speed * Timer::getInstance().getSeconds()) {
            setPosition(target);
            m_way.popFront();
        }
        else {
            m_position = m_position+ direction * m_speed * Timer::getInstance().getSeconds();
        }
        if (m_way.empty()) {
            setStatus(not_moving);
        }
    }
}

void Entity::simulate(){
    std::set<Entity*>::iterator it = s_entities.begin();
    while (it != s_entities.end()) {
        Entity* entity = *it;
        entity->update();

        if (entity->m_status == destroy) {
            it = s_entities.erase(it);  // erase returns the next valid iterator
            delete entity;
        } else {
            ++it;
        }
    }
}

void Entity::finalize() {
    for (Entity* agent : s_entities) {
        agent->m_status = destroy;
    }
}

void Entity::setStatus(Status status) {
    m_status = status;
}