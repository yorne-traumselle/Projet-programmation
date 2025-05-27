#include "Weapon.h"


Weapon::Weapon(std::string name, std::string description, float price, int bonusAttack, int bonusDefense):
	Equipment(name, description, price, EquipmentType::Weapon, bonusAttack, bonusDefense, false){}

void Weapon::equipped(Fighter& fighter){
	fighter.gainAttack(m_bonusDefense,false);
}
