#include "DefensePotion.h"

DefensePotion::DefensePotion(std::string name, std::string description, float price, int power):
	Consumable(name, description, price, TypeEffect::Defense, power){}

void DefensePotion::consume(Fighter& fighter){
	fighter.gainDef(m_power, true);
}
