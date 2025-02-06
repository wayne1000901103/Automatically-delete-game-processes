#include <windows.h>
#include <stdio.h>

void HideConsoleWindow() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE); // 隱藏命令行窗口
}

void KillProcessByName(const char* processName) {
    char command[256];
    sprintf_s(command, sizeof(command), "taskkill /F /IM %s", processName);

    // 用 CreateProcess 避免顯示命令行窗口
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));

    // 設置標準的 cmd 語法以不顯示窗口
    if (!CreateProcess(
        "C:\\Windows\\System32\\cmd.exe",   // 執行命令的路徑
        command,                            // 傳遞給 cmd 的命令
        NULL,                               // 不設置安全性
        NULL,                               // 不設置安全性
        FALSE,                              // 不繼承句柄
        CREATE_NO_WINDOW,                   // 不顯示命令行窗口
        NULL,                               // 使用父進程的環境變量
        NULL,                               // 使用父進程的當前目錄
        &si,                                // 启动信息
        &pi                                 // 进程信息
    )) {
        printf("無法啟動命令: %s\n", processName);
    }
    else {
        printf("成功終止進程: %s\n", processName);
        // 等待進程結束
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
        "steamservice.exe"
    };

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
