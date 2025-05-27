#pragma once

#include <vector>


#include "../utils/CSVReader.h"
#include "../graphics/TextureManager.h"
#include "../config.h"

#include "Cell.h"
#include "../utils/Vector2.h"

class Entity;
class Cell;
/// <summary>
/// Classe utilisée pour gérer la carte du jeu
/// </summary>
class Map {

private : 

	std::vector< std::vector<std::shared_ptr<Cell>> > m_cells;
	std::vector<std::shared_ptr<Entity>> m_entities;	//Un exemple de gestion des entitées

	unsigned int m_sizeX;    //Taille de la carte
	unsigned int m_sizeY;

	std::vector<std::shared_ptr<Cell>> m_exits;

public :

    /// <summary>
	/// Constructeur de la carte du jeu.
	/// </summary>
	/// <param name="filename">Nom du fichier csv contenant la carte du jeu.</param>
	/// <param name="roomName"></param>
	Map(std::string filename = "assets/maps/map_lvl1.csv", std::string roomName);
	// <summary>
	/// Destucteur
	/// </summary>
	virtual ~Map();

    /// <summary>
	/// Getter sur la taille de la carte.
	/// </summary>
	/// <returns>Taille</returns>
	unsigned int getSizeX() const { return m_sizeX; }
	/// <summary>
	/// Getter sur la taille de la carte.
	/// </summary>
	/// <returns>Taille</returns>
	unsigned int getSizeY() const { return m_sizeY; }
	/// <summary>
	/// Retroune le type de texture d'une case.
	/// </summary>
	/// <param name="x">Indice de la carte</param>
	/// <param name="y">Indice de la carte</param>
	/// <returns>Le type de la case</returns>
	int type(int x, int y) const;

    /// <summary>
	/// Chargement de la carte en fonction du fichier csv.
	/// </summary>
	/// <param name="filename">Nom du fichier csv contenant la carte du jeu.</param>
	void loadMap(std::string filename = "ressources/maps/map_lvl1.csv");
	/// <summary>
	/// Utilisation des textures en fonction du numéro de la case.
	/// </summary>
	void drawMap();


	const unsigned int getHeight() const;

	const unsigned int getWidth() const;

	std::shared_ptr<Cell> getCell(Vector2<unsigned int> position);

	std::vector<std::vector<bool>> getMatriceBool();

	//const MapType getMapType() const;

};
