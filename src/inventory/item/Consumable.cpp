#include "Consumable.h"

Consumable::Consumable(std::string name, std::string description, float price, TypeEffect effect, int power):
	Item(name, description, price), m_effect(effect), m_power(power){}


TypeEffect Consumable::getEffect() const{
	return m_effect;
}
