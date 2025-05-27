#include "Equipment.h"

Equipment::Equipment(std::string name, std::string description, float price, EquipmentType equipment, int bonusAttack, int bonusDefense):
	Item(name, description, price), m_equipment(equipment), m_bonusAttack(bonusAttack), m_bonusDefense(bonusDefense), m_isEquipped(false){}

EquipmentType Equipment::getEquipmentType() const{
	return m_equipment;
}

bool Equipment::isEquipped() const{
	return m_isEquipped;
}
