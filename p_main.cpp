#include "Map.h"

enum class Direction :short int{ left, right, up, back };
inline void PlayerMove(Direction PlayerMovement, short int** RealMap, short int &playerX, short int &playerY);
inline Direction Keydown(char press);
inline void BotMove(short int **RealMap,short int &BotX,short int &BotY);

int main(void) {
    /*declation & intilization*/
    short int** RealMap = new short int*[8]; 
    short int playerX = 0, playerY = 1, BotX = 5 , BotY = 8 ;
    for (short int i = 0; i < 8; i++) {RealMap[i] = new short int[16];} map(RealMap);
    RealMap[playerX][playerY] = 3; RealMap[BotX][BotY] = 4 ;
    show(RealMap); system("pause");
    // 遊戲迴圈 /game loop
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
                BotMove(RealMap,BotX,BotY);
                system("cls"); show(RealMap); printf("press q to leave ");  
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            else break;
        }
    }
    // 釋放動態記憶體 / releace dymantic memory
    for (short int i = 0; i < 8; i++) {delete[] RealMap[i];}delete[] RealMap;
    return 0;
}

inline void PlayerMove(Direction PlayerMovement, short int** RealMap, short int &playerX, short int &playerY) {
    short int newX = playerX, newY = playerY;
    switch (PlayerMovement) {
        case Direction::up:     if (playerX > 0 && RealMap[playerX - 1][playerY] != 2)  {newX = playerX - 1;}break;
        case Direction::back:   if (playerX < 7 && RealMap[playerX + 1][playerY] != 2)  {newX = playerX + 1;}break;
        case Direction::left:   if (playerY > 0 && RealMap[playerX][playerY - 1] != 2)  {newY = playerY - 1;}break;
        case Direction::right:  if (playerY < 15 && RealMap[playerX][playerY + 1] != 2) {newY = playerY + 1;}break;
    }
    if (newX != playerX || newY != playerY) {
        RealMap[playerX][playerY] = 0;   
        RealMap[newX][newY] = 3;         
        playerX = newX; playerY = newY;
    }
}
//fetch the keyboard event / 抓取鍵盤活動
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
inline void BotMove(short int**RealMap,short int &BotX,short int &BotY){
    srand(time(NULL));
    short int movement;
    bool TF=1;
    do{
        movement=rand()%4+1;
        switch(movement){
            case 1: if(RealMap[BotX-1][BotY]!=2&&BotX>=0)   { TF=0;RealMap[BotX][BotY]=0; BotX-=1; }    break;
            case 2: if(RealMap[BotX+1][BotY]!=2&&BotX<=15)  { TF=0;RealMap[BotX][BotY]=0; BotX+=1; }    break;
            case 3: if(RealMap[BotX][BotY-1]!=2&&BotY>=0)   { TF=0;RealMap[BotX][BotY]=0; BotY-=1; }    break;
            case 4: if(RealMap[BotX][BotY+1]!=2&&BotY<=15)  { TF=0;RealMap[BotX][BotY]=0; BotY+=1; }    break;
        }
    } while (TF);
    RealMap[BotX][BotY]=4;
}