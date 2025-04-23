#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstdio>
#include "sleep.h"

using namespace std;

#define SCRIPT_VERSION "1.0 [ SpeedsterX Custom Idle ]"

void Usage() {
    cout << "♨️ SPEEDSTERX " << SCRIPT_VERSION << " - Automatic Device Optimization Utility\n\n"
         << "Usage:\n"
         << "  SpeedsterX [OPTION]\n\n"
         << "Options:\n"
         << "  -d           Whitelist important system apps (sys-whitelist).\n"
         << "  -L           Whitelist user-installed apps (user-whitelist).\n"
         << "  -R           Reset all SpeedsterX modifications.\n"
         << "  -h, --help   Show this help message and exit.\n\n"
         << "Description:\n"
         << "  SpeedsterX is a performance boosting and idle optimization tool\n"
         << "  for Android devices. It automatically adjusts system settings,\n"
         << "  whitelists critical apps from device idle restrictions, and improves\n"
         << "  overall speed and battery efficiency.\n\n"
         << "Examples:\n"
         << "  Whitelist system apps:\n"
         << "      SpeedsterX -d\n\n"
         << "  Whitelist user apps:\n"
         << "      SpeedsterX -L\n\n"
         << "  Reset all modifications:\n"
         << "      SpeedsterX -R\n\n"
         << "Requirements:\n"
         << "  - Root access may be required.\n"
         << "  - Device must support 'adb shell' and device idle commands.\n\n"
         << "More Info:\n"
         << "  Android Optimization Docs: https://developer.android.com/topic/performance\n"
         << "  SpeedsterX Support Group  : https://t.me/speedsterx_support\n"
         <<"   Android Open Source Idle   : https://source.android.com/docs/core/power/app_mgmt?hl=id\n"
         << "  Community Discussions     : https://forum.xda-developers.com\n\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            sleep(1);
            cout << "- Applying system apps whitelist High...\n\n";
            idle_high();
        } else if (strcmp(argv[i], "-L") == 0) {
            sleep(1);
            cout << "- Applying user apps whitelist Low...\n\n";
            idle_low();
        } else if (strcmp(argv[i], "-R") == 0) {
            sleep(1);
            cout << "- Resetting all SpeedsterX modifications...\n\n";
            kill();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Usage();
        } else {
            cout << "Error: Unknown option '" << argv[i] << "'\n\n";
            Usage();
            return 1;
        }
    }

    sleep(1);
    cout << "\n"
         << "⚠️ This module is protected by copyright and\n"
         << "is intended for use by regular users only. Any\n"
         << "unauthorized modification, duplication, or\n"
         << "redistribution is strictly prohibited.\n"
         << "______________________________________________(+)\n\n";

    return 0;
}