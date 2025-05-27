#pragma once

#include "Fighter.h"
#include "../inventory/Inventory.h"
/// <summary>
/// Classe représentant un personnage du jeu
/// </summary>
class Hero : public Fighter {
	Inventory * m_inventory;
	int m_level;
	bool m_utilized = false;
public : 
    /// <summary>
	/// Constructeur du héro.
	/// </summary>
	/// <param name="position">Position dans le monde.</param>
    /// <param name="size">Taille (largeur et hauteur) de l'entité.</param>
    /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    Hero(Map* map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense, Inventory * inventory);
    ~Hero() override;

	void update() override;
	void render() override;

	void gainLevel();

	void useItem(const std::string & itemName);

	void startTurn() override;
};
