#ifndef __HEALPOTION__H__
#define __HEALPOTION__H__
#include "Consumable.h"

class HealPotion: public Consumable{
public:
	HealPotion(std::string name, std::string description, float price, int power);

	virtual ~HealPotion() = default;

	void consume(Fighter& fighter) override;
};
