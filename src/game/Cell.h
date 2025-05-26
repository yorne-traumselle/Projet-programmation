#pragma once

#include "Map.h"


class Cell : public Map{

  private :

    const float m_cell_size; //taille d'une tuile

    bool empty; // true si la case est vide
                // false sinon
    
    int tile; //texture de la tile en int
    Vector2<float> m_position;          //Position de la tuile dans le monde
  
  public :
    
    const float getCellSize() const;

    const bool occupied() const;

    const int getTile() const;

    void setTile(const int & tileValue);
    
};