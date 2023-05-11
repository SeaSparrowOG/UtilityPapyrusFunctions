#pragma once

namespace PapyrusVerification {
	bool Bind(VM* a_vm);
	std::vector<int32_t> GetSeaSparrowExtenderVersion(VM*, StackID a_StackID, RE::StaticFunctionTag*);
}