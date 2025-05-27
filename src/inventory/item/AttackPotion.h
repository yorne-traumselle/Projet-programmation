#ifndef __ATTACKPOTION__H__
#define __ATTACKPOTION__H__
#include "Consumable.h"

class AttackPotion: public Consumable{
public:
	AttackPotion(std::string name, std::string description, float price, int power);

	virtual ~AttackPotion() = default;

	void consume(Fighter& fight);
};
#endif
