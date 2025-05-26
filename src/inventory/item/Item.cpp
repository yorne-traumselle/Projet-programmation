#include "Item.h"

Item::Item(std::string name, std::string description, float price):
	m_name(name), m_description(description), m_price(price){}

std::string Item::getName() const{
	return m_name;
}

std::string Item::getDescription() const{
	return m_description;
}

float Item::getPrice() const{
	return m_price;
}


