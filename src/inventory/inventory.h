#ifndef __INVENTORY__H__
#define __INVENTORY__H__

#include "item.h"
#include <vector>
#include <unordered_map>

class inventory{
private:
	unsigned int m_gold;
	unordered_map<item, int> m_items;

public:
	inventory();

	void addItems(item Item, int nb);

	void deleteItem(item Item, int nb);



};
#endif
