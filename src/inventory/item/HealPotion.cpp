#include "HealPotion.h"

HealPotion::HealPotion(std::string name, std::string description, float price, int power):
	Consumable(name, description, price, TypeEffect::Heal, power){}

void HealPotion::consume(Fighter& fighter){
	fighter.getHealed(m_power);
}
