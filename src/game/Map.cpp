#include "Map.h"

#include <iostream>
#include <cassert>

Map::Map(std::string filename,unsigned int map_type){
	assert (map_type==0 || map_type==1 || map_type==2 );
	loadMap(filename);
	if (map_type==0) m_map_type=MapType::Chill;
	if (map_type==1) m_map_type=MapType::MinionFight;
	if (map_type==2) m_map_type=MapType::BossFight;
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

// Redimensionne m_cells à la bonne taille
	m_cells.resize(m_sizeY);
	for (auto& row : m_cells) {
		row.reserve(m_sizeX);  // Meilleure perf que resize + push_back
	}

	// Remplit chaque Cell avec i (ligne), j (colonne), et la tile correspondante
	for (unsigned int i = 0; i < m_sizeY; ++i) {
		for (unsigned int j = 0; j < m_sizeX; ++j) {
			int tile = m_tiles[i][j];
			m_cells[i].emplace_back(i, j, tile);  // Construction directe de la Cell
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

const unsigned int Map::getHeight() const{
	return m_cells.size();
}
const unsigned int Map::getWidth() const{
	m_cells.front().size();
}

Cell * Map::getCell(Vector2<unsigned int> position) {
	return &(m_cells.at(position[0]).at(position[1]));
}

std::vector<std::vector<bool>> Map::getMatriceBool() {
    unsigned int width = getWidth();
    unsigned int height = getHeight();

    std::vector<std::vector<bool>> matrice(width, std::vector<bool>(height, false));

    for (unsigned int  i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            Vector2<unsigned int> position(i, j);
            matrice[i][j] = !getCell(position)->occupied();
        }
    }

    return matrice;
}