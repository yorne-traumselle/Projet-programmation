#ifndef __CONSUMABLE__H__
#define __CONSUMABLE__H__
#include "item.h"

// Permet de gérer le type de consommable
enum class TypeEffect{
	Heal,
	Attack,
	Defense
};

class consumable: public item{
private:
	TypeEffect m_effect;
	int m_power;

public:
	// Constructeur
	consumable(std::string name, std::string description, float price, TypeEffect effect, int power);

	// Destructeur
	virtual ~consumable() = default;

	void utilize();

	// Donne l'effet du consommable
	TypeEffect getEffect();

};
#endif
