#include "AttackPotion.h"

AttackPotion::AttackPotion(std::string name, std::string description, float price, int power):
	Consumable(name, description, price, TypeEffect::Attack, power){}

void AttackPotion::consume(Fighter& fighter){
	fighter.gainAttack(m_power, true);
}
