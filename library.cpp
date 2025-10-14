#include <cstdio>
#include <Windows.h>

bool __stdcall DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    static FILE *p_file{nullptr};

    if (reason == DLL_PROCESS_ATTACH) {
        AllocConsole();
        freopen_s(&p_file, "CONOUT$", "w", stdout);

        while (!GetAsyncKeyState(VK_END)) {
        }

        FreeLibraryAndExitThread(instance, 0);
    }

    if (reason == DLL_PROCESS_DETACH) {
        fclose(p_file);
        FreeConsole();
    }

    return true;
}
