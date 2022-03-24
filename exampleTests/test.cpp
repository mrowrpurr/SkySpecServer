#include <SKSE/SKSE.h>
#include <RE/C/ConsoleLog.h>
#include <SkySpec/Server.h>

// TODO - use sdplog sink (or whatever) to output logs in SKSE folder

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);
    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* event){
        if (event->type == SKSE::MessagingInterface::kDataLoaded) {
            SkySpec::Server::RegisterTestSuite("My Cool Test Suite", [](){
                // TODO have this call the Notify() functions! To print to the console of the client caller.
                RE::ConsoleLog::GetSingleton()->Print("RAN MY COOL TEST SUITE!");
            });
        }
    });
    return true;
}

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface*, SKSE::PluginInfo* info) {
    info->infoVersion = SKSE::PluginInfo::kVersion;
    info->name = "SomeTests";
    info->version = 1;
    return true;
}

extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = [](){
    SKSE::PluginVersionData version;
    version.PluginName("SomeTests");
    version.PluginVersion({ 0, 0, 1 });
    version.CompatibleVersions({ SKSE::RUNTIME_LATEST });
    return version;
}();
