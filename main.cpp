    #include <iostream>
    #include <windows.h>
    #include <thread>
    #include <chrono>
    #include <cstdlib>

    using namespace std;

    bool running = true;

    void mouse(){
        POINT pos;
        GetCursorPos(&pos);
        
        int dx = (rand() % 11) - 5;
        int dy = (rand() % 11) - 5;
    
        SetCursorPos(pos.x + dx, pos.y + dy);
    }

    void presskey(WORD key){
        INPUT input = { 0 };
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = key;
        SendInput(1, &input, sizeof(INPUT));
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
    }

    void afk(){
        while (running){
            mouse();
            presskey(0x57);
            std::this_thread::sleep_for(std::chrono::seconds(10 + rand() % 10));
        }
    }

    int main(){
        std::cout << "\(0^◇^0)/" << endl;
        std::cout << "Anti-AFK is running! Press F9 to exit.\n";

        std::thread afkthread(afk);

        while (running) {
            if(GetAsyncKeyState(VK_F9) & 1){
                running = false;
                }
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        afkthread.join();
        std::cout << "Анти-AFK выключен.\n";
        Sleep(1000);
        return 0;
    }

    //Sl4ckStre1z || https://github.com/Uzko