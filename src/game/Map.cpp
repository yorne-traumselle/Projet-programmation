#include "Map.h"

#include <iostream>

Map::Map(std::string filename){
	loadMap(filename);
}

Map::~Map()
{
}

int Map::type(int x, int y) const
{
	return m_cells.at(x).at(y).getTile();
}

void Map::loadMap(std::string filename)
{	

	std::vector<std::vector<int>> m_tiles;
	m_tiles = (new CSVReader(filename))->getData();
	m_sizeY = m_tiles.size();
	m_sizeX = m_tiles.front().size();
// On affecte la vaeur de chaque tile du fichier csv aux cells 
	for (unsigned int row = 0; row < m_sizeY; ++row) { 
		for (unsigned int column = 0; column < m_sizeX; ++column) {
			m_cells.at(row).at(column).setTile(m_tiles.at(row).at(column));
		}
	}
}

void Map::drawMap()
{
	int type = -1;

	for (unsigned int row = 0; row < m_sizeY; ++row) {
		for (unsigned int column = 0; column < m_sizeX; ++column) {
			
			type = m_cells.at(row).at(column).getTile();

            SDL_Rect destRect = {
                column * JeuESIR::tileWidth,
                row * JeuESIR::tileHeight,
                JeuESIR::tileWidth,
                JeuESIR::tileHeight
            };

			Renderer::getInstance()->drawTexture(
                TextureManager::getInstance()->get(type)->get(),
                nullptr,
                &destRect
            );
			
		}
	}
}