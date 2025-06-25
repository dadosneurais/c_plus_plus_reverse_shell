#include <windows.h>

int main(){
    HMODULE hDll = LoadLibraryA("main.dll");

    if (hDll == NULL){
        return 1;
    }

    while(true){
        Sleep(1000);
    }
    return 0;
}