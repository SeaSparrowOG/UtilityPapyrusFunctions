#include <papyrusVerification.h>

namespace PapyrusVerification {
	bool Bind(VM* a_vm) {
		BIND(GetSeaSparrowExtenderVersion);
		return true;
	}

	std::vector<int32_t> GetSeaSparrowExtenderVersion(VM*, StackID a_StackID, RE::StaticFunctionTag*) {
		std::vector<int32_t> response;
		const auto pluginVersion = SKSE::PluginDeclaration::GetSingleton()->GetVersion();

		response.push_back(pluginVersion.major());
		response.push_back(pluginVersion.minor());
		response.push_back(pluginVersion.patch());

		return response;
	}
}