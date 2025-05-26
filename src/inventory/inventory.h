#ifndef __INVENTORY__H__
#define __INVENTORY__H__

#include "item/Item.h"
#include <vector>
#include <unordered_map>

class inventory{
private:
	unsigned int m_gold;
	unordered_map<Item, int> m_items;

public:
	inventory();

	void addItems(Item Item, int nb);

	void deleteItem(Item Item, int nb);



};
#endif
