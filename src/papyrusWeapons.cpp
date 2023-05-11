#include "papyrusWeapons.h"

namespace PapyrusWeapons {
	bool Bind(VM* a_vm) {
		BIND(GetEquippedAmmoEnchantment);
		BIND(GetBaseAmmoEnchantment);
		return true;
	}

	RE::EnchantmentItem* GetEquippedAmmoEnchantment(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::Actor* a_kActor) {
		RE::EnchantmentItem* response = nullptr;
		
		if (!a_kActor) {

			return response;
		}

		const auto process = a_kActor->GetActorRuntimeData().currentProcess;
		const auto middleHigh = process ? process->middleHigh : nullptr;
		const auto bothHands = middleHigh ? middleHigh->bothHands : nullptr;

		if (bothHands && bothHands->object) {
			if (const auto ammo = bothHands->object->As<RE::TESAmmo>()) {
				const auto projectile = ammo ? ammo->GetRuntimeData().data.projectile : nullptr;
				const auto explosion = projectile ? projectile->data.explosionType : nullptr;
				auto enchantment = explosion ? explosion->formEnchanting : nullptr;

				if (const auto& extraLists = bothHands->extraLists) {
					for (const auto& extraList : *extraLists) {
						const auto exEnch = extraList->GetByType<RE::ExtraEnchantment>();
						if (exEnch && exEnch->enchantment) {
							enchantment = exEnch->enchantment;
						}
					}
				}

				return enchantment;
			}
		}
		
		return response;
	}

	RE::EnchantmentItem* GetBaseAmmoEnchantment(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::TESAmmo* a_kAmmo) {
		RE::EnchantmentItem* response = nullptr;

		if (!a_kAmmo) {
			return response;
		}

		const auto projectile = a_kAmmo ? a_kAmmo->GetRuntimeData().data.projectile : nullptr;
		const auto explosion = projectile ? projectile->data.explosionType : nullptr;
		response = explosion ? explosion->formEnchanting : nullptr;

		return response;
	}
}