//
// Created by yorne-traumselle on 26/05/25.
//
#include "Spell.h"
#include <cassert>


Spell::Spell(int baseValue, CastZone castZone, EffectZone effecZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange, TypeSpell typeSpell): m_baseValue(baseValue), m_castZone(castZone), m_effectZone(effecZone), m_zoneSize(zoneSize), m_maxRange(maxRange), m_minRange(minRange), m_typeSpell(typeSpell) {
    assert(baseValue>0);
    assert(zoneSize>0);
    assert(maxRange>0);
    assert(minRange>0);
}

void Spell::cast(Vector2<unsigned int> position, Map map) {
    int length = map.getLength();
    int height = map.getHeight();
    assert(position[0] < length && position[1] < height);
    assert(position[0] >= 0 && position[1] >= 0);
    switch (m_effectZone) {
        case mono :
            if (map.getStatus(position) == free) {
                map.getTile(position).doSpell(this);
            }
            break;
        case circle:
            for(int j = -m_zoneSize; j <= m_zoneSize; j++) {
                for (int i = -m_zoneSize; i <= m_zoneSize; i++) {
                    Vector2<int> place = Vector2<int>(position[0]+i, position[1]+j);
                    if (place[0] >= 0 && place[1] >= 0 && place[0] < length && place[1] < height) {
                        if (map.getStatus(place) == free) {
                            map.getTile(place).doSpell(this);
                        }
                    }
                    break;
                }
            }
    }
}