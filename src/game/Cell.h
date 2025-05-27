#pragma once



#include "../entity/Spell.h"

class Entity;
class Cell {

  private :

    bool empty; // true si la case est vide
                // false sinon
    
    unsigned int m_tile; //texture de la tile en int

    Vector2<unsigned int> m_position;//position dans la matrice de cells

    Entity * m_entity;//adresse de l entite qui marche sur la cell

    std::string m_leadTo;//nom de la salle vers laquelle l'exit mène (="" si c pas une exit)

    bool m_isExit;

    Vector2<unsigned int> m_nextRoomSpawn;
  
  public :

    Cell(unsigned int row , unsigned int column, unsigned int tile,bool isExit=false,
      std::string leadTo="",Vector2<unsigned int> nextRoomSpawn=Vector2<unsigned int>(0,0));

    const bool occupied() const;

    const Vector2<unsigned int> getPosition() const;

    const int getTile() const;

    void setTile(const int & tileValue);

    //doit etre appelee quand une entity entre ou quitte une cellule
    //Return nullptr si personne n'est sur la cell
    void steppedOnBy(Entity * entity);

    Entity * whoIsSteppingOnMe();
    
    void doSpell(Spell * spell, Fighter& caster);

    const bool isExit() const;
    
    const std::string leadTo() const;

    const Vector2<unsigned int> nextSpawn() const;
};