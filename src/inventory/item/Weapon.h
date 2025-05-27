#ifndef __WEAPON__H__
#define __WEAPON__H__
#include "Equipment.h"

class Weapon: public Equipment{
public:
	Weapon(std::string name, std::string description, float price, int bonusAttack = 0, int bonusDefense = 0);

	virtual ~Weapon() = default;

	void equipped(Fighter& fighter);
};
#endif
