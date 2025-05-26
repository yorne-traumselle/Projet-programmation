#ifndef __EQUIPMENT__H__
#define __EQUIPMENT__H__
#include "Item.h"
#include "../../entity/Fighter.h"

enum class EquipmentType {
    Weapon,
    Armor
};

class Equipment: public Item{
private:
	EquipmentType m_equipment;
    int m_bonusAttack;
    int m_bonusDefense;
    bool m_isEquipped;

public:
	Equipment(std::string name, std::string description, float price, EquipmentType equipment, int bonusAttack = 0, int bonusDefense = 0);

	virtual ~Equipment() = default;

	EquipmentType getEquipmentType() const;

	// Permet aux équipments d'être équipés
	virtual void equipped(Fighter& fighter) = 0;

	bool isEquipped() const;
};
#endif
