#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void HideConsoleWindow() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE); // 隱藏命令行窗口
}

void KillProcessByName(const char* processName) {
    char command[256];
    // 使用 sprintf_s 代替 sprintf，增加緩衝區大小限制
    sprintf_s(command, sizeof(command), "taskkill /F /IM %s", processName);
    system(command); // 執行命令
    printf("嘗試終止進程: %s\n", processName);
}

void ShowTaskList() {
    // 使用 system 函數調用 tasklist 命令
    system("tasklist");
}

int main() {
    const char* targetProcesses[] = {
        "RobloxPlayerInstaller.exe",
        "RobloxPlayerLauncher.exe",
        "RobloxStudioInstaller.exe",
        "RobloxPlayerBeta.exe",
        "RobloxCrashHandler.exe",
        "RobloxStudioLauncherBeta.exe",
        "ZenlessZoneZero.exe",
        "StarRail.exe",
        "GenshinImpact.exe",
        "BH3.exe",
        "HYP.exe",
        "steamerrorreporter64.exe",
        "steamwebhelper.exe",
        "steamxboxutil64.exe",
        "steam_monitor.exe",
        "steamerrorreporter.exe",
        "steamxboxutil.exe",
        "steam.exe",
        "steamservice.exe",
        "Install-GooglePlayGames-Beta.exe",
        "Plain Craft Launcher 2",
        "MinecraftInstaller.exe",
        "xgamehelper.exe",
        "xgamecontrol.exe",
        "tcui-app.exe",
        "gamingservicesui.exe",
        "gamingservicestcui.exe",
        "gamingservicesnet.exe",
        "gamingservices.exe",
        "gamelaunchhelper.exe",
        "gsstub.exe",
        "createdump.exe"
    };

    // 顯示當前運行的進程
    printf("當前運行的進程：\n");
    ShowTaskList();

    // 隱藏命令行窗口
    HideConsoleWindow();

    // 無限循環，定期檢查並終止進程
    while (1) {
        for (int i = 0; i < sizeof(targetProcesses) / sizeof(targetProcesses[0]); i++) {
            KillProcessByName(targetProcesses[i]);
        }

        // 每次循環等待 1 秒
        Sleep(1000);
    }

    return 0;
}