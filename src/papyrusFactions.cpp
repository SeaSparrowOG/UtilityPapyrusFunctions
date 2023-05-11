#include "papyrusFactions.h"
#include <algorithm> 
#include <vector>

namespace PapyrusFactions {
	bool Bind(VM* a_vm) {
		BIND(GetAllActorsInFaction);
		SKSE::log::info("Bound Faction-related functions.");
		return true;
	}

	std::vector<RE::Actor*> GetAllActorsInFaction(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::TESFaction* a_kFaction) {	
		SKSE::log::info("GetAllActorsInFaction starting.");

		std::vector<RE::Actor*> response;

		if (!a_kFaction) {

			return response;
		}


		if (const auto processLists = RE::ProcessLists::GetSingleton(); processLists) {
			RE::BSTArray<RE::ActorHandle>* highActorHandles = &processLists->highActorHandles;
			RE::BSTArray<RE::ActorHandle>* middleHighActorHandles = &processLists->middleHighActorHandles;
			RE::BSTArray<RE::ActorHandle>* middleLowActorHandles = &processLists->middleLowActorHandles;
			RE::BSTArray<RE::ActorHandle>* lowActorHandles = &processLists->lowActorHandles;

			std::vector<RE::BSTArray<RE::ActorHandle>*> allActors;
			allActors.push_back(highActorHandles);
			allActors.push_back(middleHighActorHandles);
			allActors.push_back(middleLowActorHandles);
			allActors.push_back(lowActorHandles);

			for (auto array : allActors) {
				for (auto& actorHandle : *array) {
					auto actorPtr = actorHandle.get();

					if (auto actor = actorPtr.get(); actor) {
						if (actor->IsInFaction(a_kFaction)) {
							SKSE::log::info("Pushing back {}.", actor->GetName());
							response.push_back(actor);
						}
					}
				}
			}
		}
		SKSE::log::info("GetAllActorsInFaction finished.");
		return response;
	}
}