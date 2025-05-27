#ifndef CELL_H
#define CELL_H

#include "../entity/Spell.h"
#include "../entity/Entity.h"

class Cell {

  private :

    bool empty; // true si la case est vide
                // false sinon
    
    unsigned int m_tile; //texture de la tile en int

    Vector2<unsigned int> m_position;//position dans la matrice de cells

    Entity * m_entity;//adresse de l entite qui marche sur la cell
  
  public :

    Cell(unsigned int row , unsigned int column, unsigned int tile);
    
    const float getSize() const;

    const bool occupied() const;

    const int getTile() const;

    void setTile(const int & tileValue);

    //doit etre appelee quand une entity entre ou quitte une cellule
    //Return nullptr si personne n'est sur la cell
    void steppedOnBy(Entity * entity);
#include "Map.h"
    Entity * Cell::whoIsSteppingOnMe();
    
    void doSpell(Spell * spell, Fighter& caster);
};
#endif // CELL_H