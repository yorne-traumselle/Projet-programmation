//
// Created by yorne-traumselle on 26/05/25.
//

#ifndef SPELL_H
#define SPELL_H
#include "../utils/Vector2.h"
#include "../game/Map.h"

class Spell {
public:
    typedef enum{cross, classic} CastZone;
    typedef enum{circle, mono} EffectZone;
    typedef enum{attack, support} TypeSpell;
protected:
    int m_baseValue;
    CastZone m_castZone;
    EffectZone m_effectZone;
    unsigned int m_zoneSize;
    unsigned int m_maxRange;
    unsigned int m_minRange;
    TypeSpell m_typeSpell;
public:
    Spell(int baseValue, CastZone castZone, EffectZone effecZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange, TypeSpell typeSpell);
    void cast(Vector2<unsigned int> position, Map map);
    virtual void effect()=0;
};
#endif //SPELL_H
