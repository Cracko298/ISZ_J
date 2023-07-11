#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

bool IsProcessRunning(const wchar_t* processName)
{
    bool found = false;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &processEntry))
        {
            do
            {
                wchar_t wideProcessName[MAX_PATH];
                MultiByteToWideChar(CP_ACP, 0, processEntry.szExeFile, -1, wideProcessName, MAX_PATH);

                if (_wcsicmp(wideProcessName, processName) == 0)
                {
                    found = true;
                    break;
                }
            } while (Process32Next(hSnapshot, &processEntry));
        }

        CloseHandle(hSnapshot);
    }

    return found;
}

void SendKeyPress(WORD keyCode)
{
    keybd_event(keyCode, 0, 0, 0);
    keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT* pKeyboardStruct = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN && pKeyboardStruct->vkCode == VK_SPACE)
        {
            std::cout << "`set Engine.Character bPressedJump True" << std::endl;
            SendKeyPress(VK_RETURN);
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

extern "C" DLL_EXPORT void MainApp()
{
    const wchar_t* targetProcessName = L"ISZ-Plugin.exe";
    while (IsProcessRunning(targetProcessName))
    {
        HHOOK hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);

        MSG message;
        while (GetMessage(&message, NULL, 0, 0))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        UnhookWindowsHookEx(hKeyboardHook);
    }
}
