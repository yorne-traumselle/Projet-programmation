#ifndef __INVENTORY__H__
#define __INVENTORY__H__

#include "item/Item.h"
#include <string>
#include <memory>
#include <unordered_map>

class Inventory{
private:
	// L'argent disponible dans l'inventaire
	unsigned int m_gold;

	// Dictionnaire qui associe le nom de l'item au couple {item, qte}, où qte est la quantité de cette item dans l'inventaire
	std::unordered_map<std::string, std::pair<std::shared_ptr<Item>, int>> m_items;

public:
	// Constructeur
	Inventory();

	// Permet d'ajouter n fois le même item, où n à une valeur par défaut de 1
	void addItems(std::shared_ptr<Item> item, int qte = 1);

	// Permet de supprimer n fois le même item, où n à une valeur par défaut de 1
	void removeItem(const std::string& itemName, int qte = 1);

	// Permet d'afficher l'inventaire
//	void printInventory() const;

	// Donne le nombre de gold
	unsigned int getGold() const;

	// Ajoute des golds à l'inventaire
    void addGold(unsigned int amount);

    // Enlève des golds de l'inventaire
	void spendGold(unsigned int amount);

	// Permet de récupérer un item
	std::shared_ptr<Item> getItem(const std::string& itemName);

	// Permet de vérifier si l'item est déjà dans l'inventaire
	bool hasItem(const std::string& itemName) const;
};
#endif
