#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "Map.h"

enum class Direction { left, right, forward, back };

inline void PlayerMove(Direction PlayerMovement, int** RealMap, int &playerX, int &playerY);

int main(int argc, char* argv[]) {
    /*declation*/
    int** RealMap = new int*[8];
    int playerX = 0, playerY = 1;
    for (int i = 0; i < 8; i++) {RealMap[i] = new int[16];}
    map(RealMap);
    // 玩家初始位置
    RealMap[playerX][playerY] = 3;
    show(RealMap); system("pause");
    // 遊戲迴圈
    while (1) {
        if (_kbhit()) {
            char press = _getch();
            if (press == 'q' || press == 'Q') break;
            // 處理上下左右鍵
            if (press == -32) {
                press = _getch();
                switch (press) {
                    case 72: PlayerMove(Direction::forward, RealMap, playerX, playerY); break;
                    case 80: PlayerMove(Direction::back, RealMap, playerX, playerY); break;
                    case 75: PlayerMove(Direction::left, RealMap, playerX, playerY); break;
                    case 77: PlayerMove(Direction::right, RealMap, playerX, playerY); break;
                }
            } 
            // 處理 WASD 鍵
            else if (press == 'w' || press == 'a' || press == 's' || press == 'd') {
                switch (press) {
                    case 'w': PlayerMove(Direction::forward, RealMap, playerX, playerY); break;
                    case 'a': PlayerMove(Direction::left, RealMap, playerX, playerY); break;
                    case 's': PlayerMove(Direction::back, RealMap, playerX, playerY); break;
                    case 'd': PlayerMove(Direction::right, RealMap, playerX, playerY); break;
                }
            }
            system("cls"); show(RealMap); printf("press q to leave ");  
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }
    // 釋放動態記憶體
    for (int i = 0; i < 8; i++) {delete[] RealMap[i];}delete[] RealMap;
    return 0;
}

inline void PlayerMove(Direction PlayerMovement, int** RealMap, int &playerX, int &playerY) {
    int newX = playerX, newY = playerY;
    switch (PlayerMovement) {
        case Direction::forward:if (playerX > 0 && RealMap[playerX - 1][playerY] != 2)  {newX = playerX - 1;}break;
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
