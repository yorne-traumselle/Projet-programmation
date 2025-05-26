#include "Cell.h"


Cell::Cell(unsigned int i , unsigned int j, unsigned int tile): 
m_tile(tile) , 
m_position(Vector2<unsigned int>(i,j)),
m_entity(nullptr),
empty(true){
}


const bool Cell::occupied() const{
    return !empty;
}

const int Cell::getTile() const{
    return m_tile;
}

void Cell::setTile(const int & tile) {
    m_tile= tile;
}

void Cell::steppedOnBy(Entity * entity){ 
    m_entity=entity;
}

void Cell::steppedOnBy(Entity * entity){ 
    m_entity=entity;
}

Entity * Cell::whoIsSteppingOnMe(){
    return m_entity;
}

/*
void Cell::doSpell(Spell * spell){
    if (whoIsSteppingOnMe()!=nullptr){
        spell->effect(m_entity);
    }
}

*/