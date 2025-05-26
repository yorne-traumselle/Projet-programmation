#ifndef __CONSUMABLE__H__
#define __CONSUMABLE__H__
#include "Item.h"
#include "../../entity/Fighter.h"

// Permet de gérer le type de consommable
enum class TypeEffect{
	Heal,
	Attack,
	Defense
};

class Consumable: public Item{
protected:
	TypeEffect m_effect;
	int m_power;

public:
	// Constructeur
	Consumable(std::string name, std::string description, float price, TypeEffect effect, int power);

	// Destructeur
	virtual ~Consumable() = default;

	// Donne l'effet du consommable
	TypeEffect getEffect() const;

	// Permet aux objets d'être consommé
	virtual void consume(Fighter& fighter) = 0;

};
#endif
