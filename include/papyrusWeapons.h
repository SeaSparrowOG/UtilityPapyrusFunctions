#pragma once

namespace PapyrusWeapons {

    bool                 Bind(VM* a_vm);
    RE::EnchantmentItem* GetBaseAmmoEnchantment(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::TESAmmo* a_kAmmo);
    RE::EnchantmentItem* GetEquippedAmmoEnchantment(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::Actor* a_kActor);
}