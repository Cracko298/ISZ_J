#include <Windows.h>

bool g_Running = false;

void PressKey(WORD key)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void TypeString(const char* str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = 0;
        input.ki.wScan = str[i];
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.time = 0;
        input.ki.dwExtraInfo = GetMessageExtraInfo();
        SendInput(1, &input, sizeof(INPUT));
    }
}

void StartTyping()
{
    const char* textToType = "set Engine.Character bPressedJump True";
    const WORD backtickKeyCode = VK_OEM_3;

    g_Running = true;
    while (g_Running)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            Sleep(100);
            PressKey(backtickKeyCode);
            Sleep(10);
            TypeString(textToType);
            PressKey(VK_RETURN);
            Sleep(100);
        }
    }
}

extern "C" __declspec(dllexport) void MainApp()
{
    StartTyping();
}

extern "C" __declspec(dllexport) void StopTyping()
{
    g_Running = false;
}
