#include "consumable.h"

consumable::consumable(std::string name, std::string description, float price, TypeEffect effect, int power):
	item(name, description, price), m_effect(effect), m_power(power){}

void consumable::utilize(){

}

TypeEffect consumable::getEffect(){
	return m_effect;
}
