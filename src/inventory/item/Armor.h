#ifndef __ARMOR__H__
#define __ARMOR__H__
#include "Equipment.h"

class Armor: public Equipment{
public:
	Armor(std::string name, std::string description, float price, int bonusAttack = 0, int bonusDefense = 0);

	virtual ~Armor() = default;

	void equipped(Fighter& fighter);
};
#endif
