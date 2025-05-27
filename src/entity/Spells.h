//
// Created by envy on 26/05/25.
//

#pragma once
#include "Spell.h"

class DamageSpell : public Spell {
    public:
        DamageSpell(int baseValue, CastZone castZone, EffectZone effectZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange);
        void effect(Fighter& caster, Fighter& victim) override;
};



class HealSpell : public Spell {
    public:
        HealSpell(int baseValue, CastZone castZone, EffectZone effectZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange);
        void effect(Fighter& caster, Fighter& victim) override;
};

class TeleportSpell : public Spell {
    public:
        TeleportSpell(int baseValue, CastZone castZone, unsigned int maxRange, unsigned int minRange);

        void castOnCell(Map& map, Vector2<unsigned int> position,Fighter& caster) override;

        void effect(Fighter& caster, Fighter& victim) override;
    };
