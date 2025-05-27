#include "Cell.h"
#include "../entity/Fighter.h"

Cell::Cell(unsigned int i , unsigned int j, unsigned int tile,bool isExit,std::string leadTo,Vector2<unsigned int> nextRoomSpawn): 
m_tile(tile) , 
m_position(Vector2<unsigned int>(i,j)),
m_entity(nullptr),
empty(true),
m_isExit(isExit),
m_leadTo(leadTo),
m_nextRoomSpawn(nextRoomSpawn)
{
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

Entity * Cell::whoIsSteppingOnMe(){
    return m_entity;
}


void Cell::doSpell(Spell* spell, Fighter& caster) {
    if (whoIsSteppingOnMe() != nullptr) {
        Fighter* target = dynamic_cast<Fighter*>(m_entity);
        if (target) {
            spell->effect(caster, *target); // cast to Fighter&
        }
        // else you might log or handle the case where it's not a Fighter
    }
}


const bool Cell::isExit() const{
    return m_isExit;
}
    
const std::string Cell::leadTo() const{
    return m_leadTo;
}

const Vector2<unsigned int> Cell::nextSpawn() const{
    return m_nextRoomSpawn;
}


const Vector2<unsigned int> Cell::getPosition() const{
    return m_position;
}