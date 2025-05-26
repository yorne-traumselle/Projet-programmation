#ifndef __DEFENSEPOTION__H__
#define __DEFENSEPOTION__H__
#include "Consumable.h"

class DefensePotion: public Consumable{
public:
	DefensePotion(std::string name, std::string description, float price, int power);

	virtual ~DefensePotion() = default;

	void consume(Fighter& fighter) override;
};
