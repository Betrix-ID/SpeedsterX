#include "sleep.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#define Get "/sdcard/src/whilelist.txt"

using namespace std;

void shell(const char* message) {
    string cmd = "cmd notification post -S bigtext -t '♨️ SPEEDSTERX' 'Tag' '" + string(message) + "' > /dev/null 2>&1";
    system(cmd.c_str());
}

void idle_low() {
    cout << "Description:\n"
         << "Executes a controlled optimization routine aimed at minimizing resource\n"
         << "usage by pushing non-critical applications into low-priority idle states.\n"
         << "This operation maintains essential background tasks while extending\n"
         << "battery life and reducing unnecessary wake locks during device inactivity.\n"
         << "It achieves this by adjusting Doze settings, forcing idle states,\n"
         << "and setting specific apps to 'inactive' with moderated memory usage.\n" << endl;
    fflush(stdout);

    FILE *file = fopen(Get, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    printf("\n   Applications on Low Priority Doze Mode\n");
    printf("x--------------------------------------x\n\n");
    fflush(stdout);

    char cmd[512], commod[512];
    while (fgets(cmd, sizeof(cmd), file) != NULL) {
        cmd[strcspn(cmd, "\n")] = '\0';
        cmd[strcspn(cmd, "\r")] = '\0';

        if (cmd[0] != '+' && cmd[0] != '-' && cmd[0] != '=') {
            char temp[512];
            snprintf(temp, sizeof(temp), "+%s", cmd);
            strncpy(cmd, temp, sizeof(cmd));
        }

        const char *ops[] = {
            "cmd activity set-stop-user-on-switch false > /dev/null 2>&1",
            "cmd deviceidle enable deep > /dev/null 2>&1",
            "cmd deviceidle enabled deep > /dev/null 2>&1",
            "cmd deviceidle force-idle deep > /dev/null 2>&1",
            "cmd deviceidle force-inactive > /dev/null 2>&1",
            "cmd activity idle-maintenance > /dev/null 2>&1",
            "sm idle-maint run > /dev/null 2>&1",
            "sm fstrim > /dev/null 2>&1",
            "am kill-all",
            "sync"
        };

        for (int i = 0; i < sizeof(ops) / sizeof(ops[0]); i++)
            system(ops[i]);

        system("cmd activity memory-factor set MODERATE ");
        snprintf(commod, sizeof(commod), "cmd deviceidle whitelist %s", cmd);
        system(commod);
        snprintf(commod, sizeof(commod), "cmd activity set-inactive %s true", cmd);
        system(commod);
    }
        shell("Success: Applay SpeedsterX Low Mode Idle...");
    fclose(file);
}

void idle_high() {
    cout << "Description:\n"
         << "Executes a high-priority optimization for selected applications to ensure\n"
         << "their operations are not interrupted during Doze mode or deep idle phases.\n"
         << "This method configures the device to maintain real-time responsiveness\n"
         << "for critical apps, essential services, or user-specified processes.\n"
         << "It modifies idle whitelists, memory settings, and Doze behavior\n"
         << "to guarantee optimal performance under stringent system sleep policies.\n" << endl;
    fflush(stdout);

    FILE *file = fopen(Get, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    printf("\n   Applications on High Priority Doze Mode\n");
    printf("x--------------------------------------x\n\n");
    fflush(stdout);

    char cmd[512], commod[512];
    while (fgets(cmd, sizeof(cmd), file) != NULL) {
        cmd[strcspn(cmd, "\n")] = '\0';
        cmd[strcspn(cmd, "\r")] = '\0';

        if (cmd[0] != '+' && cmd[0] != '-' && cmd[0] != '=') {
            char temp[512];
            snprintf(temp, sizeof(temp), "+%s", cmd);
            strncpy(cmd, temp, sizeof(cmd));
        }

        const char *ops[] = {
            "cmd activity set-stop-user-on-switch false > /dev/null 2>&1",
            "cmd deviceidle enable all > /dev/null 2>&1",
            "cmd deviceidle enabled all > /dev/null 2>&1",
            "cmd deviceidle force-idle all > /dev/null 2>&1",
            "cmd deviceidle force-inactive > /dev/null 2>&1",
            "cmd activity idle-maintenance > /dev/null 2>&1",
            "sm idle-maint run > /dev/null 2>&1",
            "sm fstrim > /dev/null 2>&1",
            "am kill-all",
            "sync"
        };

        for (int i = 0; i < sizeof(ops) / sizeof(ops[0]); i++)
            system(ops[i]);

        system("cmd activity memory-factor set CRITICAL ");
        snprintf(commod, sizeof(commod), "cmd deviceidle except-idle-whitelist %s", cmd);
        system(commod);
        snprintf(commod, sizeof(commod), "cmd activity set-inactive %s true", cmd);
        system(commod);
    }
   shell("Success: Applay SpeedsterX High Mode Idle...");
    fclose(file);
}

void kill() {
    cout << "Description:\n"
         << "Performs a complete rollback of all previously applied optimizations,\n"
         << "restoring the device's idle and memory management systems back\n"
         << "to their default behavior. This includes resetting device idle\n"
         << "whitelists, stopping any forced maintenance tasks, and re-enabling\n"
         << "normal application lifecycle handling to ensure system stability\n"
         << "and standard battery management profiles.\n" << endl;
     fflush(stdout);

    const char *ops[] = {
        "cmd deviceidle unforce > /dev/null 2>&1",
        "cmd deviceidle disable all > /dev/null 2>&1",
        "cmd deviceidle except-idle-whitelist reset > /dev/null 2>&1",
        "sm idle-maint abort > /dev/null 2>&1",
        "am kill-all",
        "sync"
    };

    for (int i = 0; i < sizeof(ops) / sizeof(ops[0]); i++)
      system(ops[i]);
      system("cmd activity memory-factor reset ");
      shell("Success: Reset SpeedsterX Mode Idle...");
}