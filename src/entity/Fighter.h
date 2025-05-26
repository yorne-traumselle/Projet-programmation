//
// Created by yorne-traumselle on 26/05/25.
//

#ifndef FIGHTER_H
#define FIGHTER_H
#include "Entity.h"

class Fighter : public Entity {
public:
    typedef enum {myTurn, inFight, notInFight} FighterStatus;
protected :

    int m_maxHP;
    int m_HP;
    int m_MP[2];
    int m_attack[2];
    int m_defense[2];
    FighterStatus m_fighterStatus;

public:
    Fighter(Map* map, Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, const int HP, const int MP, const int attack, const int defense);

     ~Fighter() override = default;

    // Version de setPosition pour les combattants
    void setPosition(const Vector2<unsigned int>& position) override;

    // méthode de calcul de distance entière entre deux vecteurs
    static unsigned int distance(const Vector2<unsigned int>& v1, const Vector2<unsigned int>& v2);

    void takeDamage(int damage);

    void getHealed(int heal);

    unsigned int getHP() const;

    void gainDef(int def, bool inFight);
    void gainMP(int mp, bool inFight);
    void gainAttack(int attack, bool inFight);
    void useSpell(Vector2<unsigned int> position, int spellID);
    void update() override;
    unsigned int getAttack() const;
    unsigned int getDefense() const;
};
#endif //FIGHTER_H
