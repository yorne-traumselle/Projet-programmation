//
// Created by yorne-traumselle on 26/05/25.
//
#include "Spell.h"
#include "../game/Map.h"
#include <cassert>
#include <set>

Spell::Spell(int baseValue, CastZone castZone, EffectZone effecZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange, TypeSpell typeSpell): m_baseValue(baseValue), m_castZone(castZone), m_effectZone(effecZone), m_zoneSize(zoneSize), m_maxRange(maxRange), m_minRange(minRange), m_typeSpell(typeSpell) {
    assert(baseValue>0);
    assert(zoneSize>0);
    assert(maxRange>0);
    assert(minRange>0);
}

void Spell::cast(Fighter& caster, Vector2<unsigned int> position, Map& map) {
    int length = map.getWidth();
    int height = map.getHeight();
    assert(position[0] < length && position[1] < height);
    assert(position[0] >= 0 && position[1] >= 0);
    switch (m_effectZone) {
        case mono :

            map.getCell(position)->doSpell(this, caster);

            break;
        case circle:
            for (int j = 0; j <= m_zoneSize; ++j) {
                for (int i = 0; i + j <= m_zoneSize; ++i) {
                    std::set<Vector2<int>> uniqueOffsets;
                    uniqueOffsets.insert(Vector2<int>(i, j));
                    uniqueOffsets.insert(Vector2<int>(-i, j));
                    uniqueOffsets.insert(Vector2<int>(i, -j));
                    uniqueOffsets.insert(Vector2<int>(-i, -j));


                    for (const auto& offset : uniqueOffsets) {
                        Vector2<int> place = Vector2<int>(position[0], position[1]) + offset;
                        if (checkInMap(place, map) ) {
                            map.getCell(place)->doSpell(this, caster);
                        }
                    }
                }
            }
    }
}

bool Spell::checkInMap(Vector2<int> place, const Map& map) {
    if (place[0] < 0 || place[1] < 0 || place[0] >= map.getWidth() || place[1] >= map.getHeight()) {
        return false;
    }
    return true;
}

void Spell::castOnCell(Map& map, Vector2<unsigned int> position, Fighter& caster) {
    cast(caster, position, map);
}