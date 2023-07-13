#include <Windows.h>

bool g_Running = false;

extern "C"
{
int printf(const char *format, ...);
}


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
        WORD keyCode = VkKeyScanA(str[i]); // Converts string to Keyboard Input

        if (keyCode & 0x0100)
        {
            PressKey(VK_SHIFT);
        }

        PressKey(keyCode & 0xFF);

        if (keyCode & 0x0100)
        {
            PressKey(VK_SHIFT);
        }
    }
}

void StartTyping()
{
    const char* textToType = "set Engine.Character bPressedJump True";
    const WORD backtickKeyCode = VK_OEM_3; // Backtick code

    g_Running = true;
    while (g_Running)
    {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            Sleep(50);
            PressKey(backtickKeyCode);
            TypeString(textToType);
            PressKey(VK_RETURN);
        }
    }
}

extern "C" __declspec(dllexport) void MainApp() // Entry Point
{
    printf( "ISZF Dialogue: ISZ_J Has Been Loaded.\n" );
    printf( "\n" );
    printf( "DLL Version: v3.0\n" );
    printf( "ISZ_J is Under Apache-2.0 License.\n" );
    StartTyping();
}

extern "C" __declspec(dllexport) void StopTyping() // Failsafe
{
    g_Running = false;
}
