#pragma once

namespace PapyrusFactions {

    bool                       Bind(VM* a_vm);
    std::vector<RE::Actor*>   GetAllActorsInFaction(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::TESFaction* a_kFaction);
}