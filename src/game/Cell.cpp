#include "Cell.h"

const float Cell::getCellSize() const{
	return m_cell_size;
}

const bool Cell::occupied() const{
    return !empty;
}

const int Cell::getTile() const{
    return tile;
}

void Cell::setTile(const int & tileValue) {
    tile= tileValue;
}

