#include <conio.h> 
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "Map.h"

enum class Direction { left, right, up, back };
inline void PlayerMove(Direction PlayerMovement, int** RealMap, int &playerX, int &playerY);
inline Direction Keydown(char press);

int main(int argc, char* argv[]) {
    /*declation & intilization*/
    int** RealMap = new int*[8]; int playerX = 0, playerY = 1;
    for (int i = 0; i < 8; i++) {RealMap[i] = new int[16];} map(RealMap);
    // 玩家初始位置
    RealMap[playerX][playerY] = 3;
    show(RealMap); system("pause");
    // 遊戲迴圈
    while (1) {
        if (_kbhit()) {
            char press=_getch();
            if(press!='q'&&press!='Q'){
                Direction PlayerKeydown;
                PlayerKeydown=Keydown(press);
                switch (PlayerKeydown) {
                    case Direction::up:     PlayerMove(Direction::up, RealMap, playerX, playerY);   break;
                    case Direction::back:   PlayerMove(Direction::back, RealMap, playerX, playerY); break;
                    case Direction::left:   PlayerMove(Direction::left, RealMap, playerX, playerY); break;
                    case Direction::right:  PlayerMove(Direction::right, RealMap, playerX, playerY);break;
                }
                system("cls"); show(RealMap); printf("press q to leave ");  
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            else break;
        }
    }
    // 釋放動態記憶體
    for (int i = 0; i < 8; i++) {delete[] RealMap[i];}delete[] RealMap;
    return 0;
}

inline void PlayerMove(Direction PlayerMovement, int** RealMap, int &playerX, int &playerY) {
    int newX = playerX, newY = playerY;
    switch (PlayerMovement) {
        case Direction::up:     if (playerX > 0 && RealMap[playerX - 1][playerY] != 2)  {newX = playerX - 1;}break;
        case Direction::back:   if (playerX < 7 && RealMap[playerX + 1][playerY] != 2)  {newX = playerX + 1;}break;
        case Direction::left:   if (playerY > 0 && RealMap[playerX][playerY - 1] != 2)  {newY = playerY - 1;}break;
        case Direction::right:  if (playerY < 15 && RealMap[playerX][playerY + 1] != 2) {newY = playerY + 1;}break;
    }
    // 只有在玩家位置變動時才更新地圖
    if (newX != playerX || newY != playerY) {
        RealMap[playerX][playerY] = 0;   
        RealMap[newX][newY] = 3;         
        playerX = newX; playerY = newY;
    }
}

inline Direction Keydown(char press){
    Direction PlayerKeydown;
    if (press == -32) {
        press = _getch();
        switch (press){
        case 72:PlayerKeydown=Direction::up;        break;
        case 80:PlayerKeydown=Direction::back;      break;
        case 75:PlayerKeydown=Direction::left;      break;
        case 77:PlayerKeydown=Direction::right;     break;
        }
    }
    // 處理 WASD 鍵
    else if (press == 'w' || press == 'a' || press == 's' || press == 'd') {
        switch (press) {
            case 'w': PlayerKeydown=Direction::up;      break;
            case 'a': PlayerKeydown=Direction::left;    break;
            case 's': PlayerKeydown=Direction::back;    break;
            case 'd': PlayerKeydown=Direction::right;   break;
        }
    }
    return PlayerKeydown;
}