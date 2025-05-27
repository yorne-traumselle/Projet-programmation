#include "Inventory.h"
#include <cassert>
#include <stdexcept>

Inventory::Inventory():m_gold(300){}

void Inventory::addItems(std::shared_ptr<Item> item, int qte){
	std::string itemName = item->getName();
	if(hasItem(itemName)){
		m_items[itemName].second += qte;
	}else{
		m_items[itemName] = {item, qte};
	}
}

void Inventory::removeItem(const std::string& itemName, int qte){
	assert(hasItem(itemName));
	int quantity = m_items[itemName].second;
	if(quantity <= qte ){
		m_items.erase(itemName);
	}else{
		m_items[itemName].second -= qte;
	}
}

unsigned int Inventory::getGold() const{
	return m_gold;
}


void Inventory::addGold(unsigned int amount){
	m_gold += amount;
}

// à voir si on affiche un truc dans le jeu
void Inventory::spendGold(unsigned int amount){
	if (amount > m_gold) {
	    throw std::runtime_error("Pas assez d'or !");
	}
	m_gold -= amount;
}

std::shared_ptr<Item> Inventory::getItem(const std::string& itemName){
    if(!hasItem(itemName)){
    	return nullptr;
    }
    return m_items[itemName].first;
}


bool Inventory::hasItem(const std::string& itemName) const{
	return m_items.find(itemName) != m_items.end();
}
