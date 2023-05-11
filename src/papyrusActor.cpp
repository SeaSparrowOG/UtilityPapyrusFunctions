#include <papyrusActor.h>

namespace PapyrusActor {
	bool Bind(VM* a_vm) {
		BIND(GetAllActorPlayableSpells);
		SKSE::log::info("Bound Actor-related functions.");
		return true;
	}

	std::vector<RE::SpellItem*> GetAllActorPlayableSpells(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::Actor* a_kActor) {
		SKSE::log::info("GetAllActorPlayableSpells starting.");

		std::vector<RE::SpellItem*> response;

		if (!a_kActor) {

			return response;
		}
		
		auto& tempSpells = a_kActor->GetActorRuntimeData().addedSpells;
		
		for (auto actorSpell : tempSpells) {
			if (actorSpell->GetSpellType() == RE::MagicSystem::SpellType::kSpell) {
				SKSE::log::info("Pushing back {}.", actorSpell->GetName());
				response.push_back(actorSpell);
			}
		}
		
		auto tempBaseSpells = a_kActor->GetActorBase()->GetSpellList();
		
		for (auto& actorBaseSpell : std::span(tempBaseSpells->spells, tempBaseSpells->numSpells)) {
			if (actorBaseSpell->GetSpellType() == RE::MagicSystem::SpellType::kSpell) {
				SKSE::log::info("Pushing back base spell {}.", actorBaseSpell->GetName());
				response.push_back(actorBaseSpell);
			}
		}
		
		SKSE::log::info("GetAllActorPlayableSpells finishing.");
		return response;
	}
}