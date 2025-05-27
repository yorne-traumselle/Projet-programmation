//
// Created by yorne-traumselle on 26/05/25.
//

#pragma once
#include "../utils/Vector2.h"
class Map;
class Fighter;
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
    virtual ~Spell() = default;
    virtual void cast(Fighter& caster,Vector2<unsigned int> position, Map& map);
    virtual void effect(Fighter& caster, Fighter& victim)=0;

    static bool checkInMap(Vector2<int> place, const Map& map);

    virtual void castOnCell(Map& map, Vector2<unsigned int> position, Fighter& caster);

    unsigned getMaxRange() const;
};
