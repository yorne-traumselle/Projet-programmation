#include "item.h"

item::item(std::string name, std::string description, float price):
	m_name(name), m_description(description), m_price(price){}

std::string item::getName() const{
	return m_name;
}

std::string item::getDescription() const{
	return m_description;
}

float item::getPrice() const{
	return m_price;
}


