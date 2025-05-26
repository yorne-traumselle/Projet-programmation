#include "Armor.h"


Armor::Armor(std::string name, std::string description, float price, int bonusAttack, int bonusDefense):
	Equipment(name, description, price, EquipmentType::Armor, bonusAttack, bonusDefense, false){}

void Armor::equipped(Fighter& fighter){
	fighter.gainDef(m_bonusDefense,false);
}
