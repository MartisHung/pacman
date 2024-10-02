#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

    /*
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    */
enum class direction { left, right, forward, back };
inline void show(int RealMap[8][16]);
inline void PlayerMove(direction PlayerMovement, int RealMap[8][16], int &playerX, int &playerY);
int main(int argc,char* argv[]) {
    int RealMap[8][16];
    // 動態宣告 Dymantic declation
    bool** area = new bool*[8];
    for (int i = 0; i < 8; ++i) { area[i] = new bool[16]; }

    area[0][0]=0;area[0][1]=0;area[0][2]=0;area[0][3]=0;area[0][4]=0;area[0][5]=0;area[0][6]=0;area[0][7]=0;
    area[0][8]=0;area[0][9]=0;area[0][10]=0;area[0][11]=0;area[0][12]=0;area[0][13]=0;area[0][14]=0;area[0][15]=0;
    area[1][0]=0;area[1][1]=1;area[1][2]=1;area[1][3]=1;area[1][4]=1;area[1][5]=1;area[1][6]=1;area[1][7]=1;
    area[1][8]=1;area[1][9]=1;area[1][10]=1;area[1][11]=1;area[1][12]=1;area[1][13]=1;area[1][14]=1;area[1][15]=0;
    area[2][0]=0;area[2][1]=1;area[2][2]=1;area[2][3]=0;area[2][4]=0;area[2][5]=0;area[2][6]=0;area[2][7]=1;
    area[2][8]=1;area[2][9]=0;area[2][10]=0;area[2][11]=0;area[2][12]=0;area[2][13]=1;area[2][14]=1;area[2][15]=0;
    area[3][0]=0;area[3][1]=1;area[3][2]=1;area[3][3]=1;area[3][4]=1;area[3][5]=1;area[3][6]=1;area[3][7]=1;
    area[3][8]=1;area[3][9]=1;area[3][10]=1;area[3][11]=1;area[3][12]=1;area[3][13]=1;area[3][14]=1;area[3][15]=0;
    area[4][0]=0;area[4][1]=1;area[4][2]=1;area[4][3]=1;area[4][4]=0;area[4][5]=0;area[4][6]=1;area[4][7]=1;
    area[4][8]=1;area[4][9]=1;area[4][10]=1;area[4][11]=0;area[4][12]=0;area[4][13]=1;area[4][14]=1;area[4][15]=0;
    area[5][0]=0;area[5][1]=1;area[5][2]=0;area[5][3]=0;area[5][4]=0;area[5][5]=0;area[5][6]=0;area[5][7]=0;
    area[5][8]=0;area[5][9]=0;area[5][10]=0;area[5][11]=0;area[5][12]=0;area[5][13]=0;area[5][14]=1;area[5][15]=0;
    area[6][0]=0;area[6][1]=1;area[6][2]=1;area[6][3]=1;area[6][4]=1;area[6][5]=1;area[6][6]=1;area[6][7]=1;
    area[6][8]=1;area[6][9]=1;area[6][10]=1;area[6][11]=1;area[6][12]=1;area[6][13]=1;area[6][14]=1;area[6][15]=0;
    area[7][0]=0;area[7][1]=0;area[7][2]=0;area[7][3]=0;area[7][4]=0;area[7][5]=0;area[7][6]=0;area[7][7]=0;
    area[7][8]=0;area[7][9]=0;area[7][10]=0;area[7][11]=0;area[7][12]=0;area[7][13]=0;area[7][14]=0;area[7][15]=0;
    const bool* const* const_area = area;
    for (int i = 0; i < 8; i++) {for (int j = 0; j < 16; j++) {RealMap[i][j] = (area[i][j]) ? 1 : 2;}}
    for (int i = 0; i < 8; ++i) { delete[] area[i]; } delete[] area;
    // 玩家初始位置
    int playerX = 0, playerY = 1;
    RealMap[playerX][playerY] = 3;
    show(RealMap);
    system("pause");
    //遊戲迴圈 game loop
    while (1) {
        if (_kbhit()) {
            char press = _getch();
            if (press == 'q' || press == 'Q') break;
            /*上下左右鍵(keydown : up/down/left/right)*/
            if (press == -32) {
                press = _getch();
                switch (press) {
                    case 72: PlayerMove(direction::forward, RealMap, playerX, playerY); break;
                    case 80: PlayerMove(direction::back, RealMap, playerX, playerY); break;
                    case 75: PlayerMove(direction::left, RealMap, playerX, playerY); break;
                    case 77: PlayerMove(direction::right, RealMap, playerX, playerY); break;
                }
            } 
            // 處理 WASD 鍵
            else if (press == 'w' || press == 'a' || press == 's' || press == 'd') {
                switch (press) {
                    case 'w': PlayerMove(direction::forward, RealMap, playerX, playerY); break;
                    case 'a': PlayerMove(direction::left, RealMap, playerX, playerY); break;
                    case 's': PlayerMove(direction::back, RealMap, playerX, playerY); break;
                    case 'd': PlayerMove(direction::right, RealMap, playerX, playerY); break;
                }
            }

            system("cls");show(RealMap);  
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}

inline void show(int RealMap[8][16]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            switch (RealMap[i][j]) {
                case 0: printf(" "); break;
                case 1: printf("."); break;
                case 2: printf("#"); break;
                case 3: printf("P"); break;
            }
        }
        printf("\n");
    }
    printf("press q to leave ");
}

inline void PlayerMove(direction PlayerMovement, int RealMap[8][16], int &playerX, int &playerY) {
    // 根據方向移動玩家
    int newX = playerX, newY = playerY;
    switch (PlayerMovement) {
        case direction::forward:if (playerX > 0 && RealMap[playerX - 1][playerY] != 2)  {newX = playerX - 1;}break;
        case direction::back:   if (playerX < 7 && RealMap[playerX + 1][playerY] != 2)  {newX = playerX + 1;}break;
        case direction::left:   if (playerY > 0 && RealMap[playerX][playerY - 1] != 2)  {newY = playerY - 1;}break;
        case direction::right:  if (playerY < 15 && RealMap[playerX][playerY + 1] != 2) {newY = playerY + 1;}break;
    }

    // 只有在玩家位置變動時才更新地圖
    if (newX != playerX || newY != playerY) {
        RealMap[playerX][playerY] = 0;   
        RealMap[newX][newY] = 3;         
        playerX = newX;playerY = newY;
    }
}
