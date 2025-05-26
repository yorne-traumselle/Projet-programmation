#include "Map.h"

#include <iostream>

Map::Map(std::string filename)
{
	loadMap(filename);
}

Map::~Map()
{
}

int Map::type(int x, int y) const
{
	return m_map.at(x).at(y);
}

void Map::loadMap(std::string filename)
{
	m_map = (new CSVReader(filename))->getData();
	m_sizeY = m_map.size();
	m_sizeX = m_map.front().size();
}

void Map::drawMap()
{
	int type = -1;

	for (unsigned int row = 0; row < m_sizeY; ++row) {
		for (unsigned int column = 0; column < m_sizeX; ++column) {
			
			type = m_map.at(row).at(column);

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