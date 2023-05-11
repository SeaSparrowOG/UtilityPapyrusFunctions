#include <papyrusFactions.h>
#include <papyrusWeapons.h>
#include <papyrusActor.h>
#include <papyrusVerification.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace logger = SKSE::log;

//Logging
void InitializeLogging() {
    auto logsFolder = SKSE::log::log_directory();
    if (!logsFolder) SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
    auto pluginName = SKSE::PluginDeclaration::GetSingleton()->GetName();
    auto logFilePath = *logsFolder / std::format("{}.log", pluginName);
    auto fileLoggerPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFilePath.string(), true);
    auto loggerPtr = std::make_shared<spdlog::logger>("log", std::move(fileLoggerPtr));
    spdlog::set_default_logger(std::move(loggerPtr));
    spdlog::set_level(spdlog::level::trace);
    spdlog::flush_on(spdlog::level::trace);
}

//Plugin declaration
SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    InitializeLogging();

    logger::info("Loading SeaSparrow's Papyrus Extender.");
    SKSE::Init(skse);

    //Bind the papyrus functions.
    if (!SKSE::GetPapyrusInterface()->Register(PapyrusFactions::Bind)) {
        return false;
    }
    if (!SKSE::GetPapyrusInterface()->Register(PapyrusActor::Bind)) {
        return false;
    }
    if (!SKSE::GetPapyrusInterface()->Register(PapyrusWeapons::Bind)) {
        return false;
    }
    if (!SKSE::GetPapyrusInterface()->Register(PapyrusVerification::Bind)) {
        return false;
    }

    logger::info("SeaSparrow's Papyrus Extender has loaded successfully.");
    return true;
}