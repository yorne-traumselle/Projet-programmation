#ifndef _CONFIG_H
#define _CONFIG_H

//caractéristiques de bases des textures de la carte et de l'écran
namespace JeuESIR
{
	// Constantes definissant la taille de la tile.
	static const unsigned int originalTileHeight = 32;				//16 x 16 Tiles
	static const unsigned int originalTileWidth = 32;
	static const unsigned int tileHeight = originalTileHeight * 1;	//1 -> scale   // 32 x 1 = 32 Tile (32 x 32)	
	static const unsigned int tileWidth = originalTileWidth *   1;

	// Constantes definissant la taille du screen en fonction des tiles.
	static const unsigned int maxScreenCol = 16;
	static const unsigned int maxScreenRow = 12;//20
	static const unsigned int screenWidth = tileWidth * maxScreenCol;	//480
	static const unsigned int screenHeight = tileHeight * maxScreenRow;	//608		

}

#endif //_CONFIG_H