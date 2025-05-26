#ifndef __ITEM__H__
#define __ITEM__H__

#include <string>

class item{
protected:
	std::string m_name;
	std::string m_description;
	float m_price;

public:
	// Constructeur
	item(std::string name, std::string description, float price);

	// Destructeur
	virtual ~item() = default;

	// Pour obtenir le nom de l'item
	std::string getName() const;

	// Pour obtenir la description de l'item
	std::string getDescription() const;

	// Pour obtenir le prix d'achat de l'item
	float getPrice() const;
};
#endif
