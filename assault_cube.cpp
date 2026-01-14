#include <windows.h>
#include <tlhelp32.h>
#include <cmath>
#include <chrono>
#include <iostream>
#include <cstdint>

DWORD GetProcessIdByName(const wchar_t *processName)
{
    DWORD pid = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(hSnapshot, &pe32))
    {
        do
        {
            if (_wcsicmp(pe32.szExeFile, processName) == 0)
            {
                pid = pe32.th32ProcessID;
                break;
            }
        } while (Process32NextW(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return pid;
}

uintptr_t GetModuleBaseAddress(DWORD pid, const wchar_t *moduleName)
{
    uintptr_t baseAddr = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    MODULEENTRY32W me32;
    me32.dwSize = sizeof(MODULEENTRY32W);

    if (Module32FirstW(hSnapshot, &me32))
    {
        do
        {
            if (_wcsicmp(me32.szModule, moduleName) == 0)
            {
                baseAddr = (uintptr_t)me32.modBaseAddr;
                break;
            }
        } while (Module32NextW(hSnapshot, &me32));
    }

    CloseHandle(hSnapshot);
    return baseAddr;
}

int main()
{
    const wchar_t *processName = L"ac_client.exe";
    DWORD pid = GetProcessIdByName(processName);

    if (pid == 0)
    {
        std::wcout << L"Process '" << processName << L"' not found!\n";
        return 1;
    }

    std::cout << "Found process ID:  " << pid << "\n";

    HANDLE hProc = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION,
                               FALSE, pid);
    if (!hProc)
    {
        std::cout << "Failed to open process\n";
        return 1;
    }

    uintptr_t baseAddr = GetModuleBaseAddress(pid, processName);
    if (baseAddr == 0)
    {
        std::cout << "Failed to get module base address\n";
        CloseHandle(hProc);
        return 1;
    }

    std::cout << "Base address: 0x" << std::hex << baseAddr << std::dec << "\n";

    uintptr_t pointerAddr = baseAddr + 0x0017E0A8;
    DWORD playerBase = 0;

    std::cout << "Reading pointer at:  0x" << std::hex << pointerAddr << std::dec << "\n";

    if (!ReadProcessMemory(hProc, (LPCVOID)pointerAddr, &playerBase, sizeof(DWORD), nullptr))
    {
        std::cout << "Failed to read player base pointer\n";
        CloseHandle(hProc);
        return 1;
    }

    if (playerBase == 0)
    {
        std::cout << "Player base pointer is null\n";
        CloseHandle(hProc);
        return 1;
    }

    std::cout << "Player base: 0x" << std::hex << playerBase << std::dec << "\n";

    uintptr_t yAddr = playerBase + 0x30;

    std::cout << "Y coordinate address: 0x" << std::hex << yAddr << std::dec << "\n";

    float baseY = 0.0f;
    if (!ReadProcessMemory(hProc, (LPCVOID)yAddr, &baseY, sizeof(baseY), nullptr))
    {
        std::cout << "Failed to read base Y\n";
        CloseHandle(hProc);
        return 1;
    }

    std::cout << "Base Y = " << baseY << "\n";

    const float amplitude = 6.0f;
    const float speed = 5.0f;

    auto start = std::chrono::steady_clock::now();

    while (true)
    {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<float> diff = now - start;
        float t = diff.count();

        float newY = std::abs(baseY + amplitude * std::sin(speed * t));

        if (!WriteProcessMemory(hProc, (LPVOID)yAddr, &newY, sizeof(newY), nullptr))
        {
            std::cout << "Failed to write Y (process may have closed)\n";
            break;
        }

        Sleep(10);
    }

    CloseHandle(hProc);
    return 0;
}
