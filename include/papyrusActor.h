#pragma once

namespace PapyrusActor {

    bool                         Bind(VM* a_vm);
    std::vector<RE::SpellItem*>  GetAllActorPlayableSpells(VM*, StackID a_StackID, RE::StaticFunctionTag*, RE::Actor* a_kActor);
}