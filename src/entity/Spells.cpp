//
// Created by envy on 26/05/25.
//
#include "Spells.h"
#include "Fighter.h"


DamageSpell::DamageSpell(int baseValue, CastZone castZone, EffectZone effectZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange):
	Spell(baseValue, castZone, effectZone, zoneSize, maxRange, minRange, attack){}

void DamageSpell::effect(Fighter& caster, Fighter& victim) {
    caster.takeDamage(m_baseValue*caster.getAttack()* (100+victim.getDefense()/100));
}

HealSpell::HealSpell(int baseValue, CastZone castZone, EffectZone effectZone, unsigned int zoneSize, unsigned int maxRange, unsigned int minRange):Spell(baseValue, castZone, effectZone, zoneSize, maxRange, minRange, support){}

void HealSpell::effect(Fighter& caster, Fighter& victim) {
    victim.getHealed(m_baseValue);
}

TeleportSpell::TeleportSpell(int baseValue, CastZone castZone, unsigned int maxRange, unsigned int minRange):Spell(baseValue, castZone, mono, 0, maxRange, minRange, teleportation){}

void TeleportSpell::castOnCell(Map& map, Vector2<unsigned int> position,Fighter& caster) {
    if (!map.getCell(position)->occupied()) {
        caster.setPositionDirectly(position);
    }
}

void TeleportSpell::effect(Fighter& caster, Fighter& victim){}

