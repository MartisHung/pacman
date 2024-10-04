#include "Map.h"
enum class Direction :short int{ left, right, up, back };
inline void PlayerMove(Direction PlayerMovement, short int** RealMap, short int *location);
inline Direction Keydown(char press);
inline void BotMove(short int **RealMap,short int *location);
int main(void) {
    /*declation & intilization*/
    bool TF=1;short int** RealMap = new short int*[MapX];
    /*playerX,playerY,botX,botY*/
    short int  *location = new short int[4];
    location[0]=0; location[1]=1; location[2]=5; location[3]=8;
    for (short int i = 0; i < 8; i++) {RealMap[i] = new short int[MapY];} map(RealMap);
    RealMap[location[0]][location[1]] = 3;show(RealMap,TF,location);
    system("pause");
    // 遊戲迴圈 /game loop
    while (TF) {
        if (_kbhit()) {
            char press=_getch();
            Direction PlayerKeydown;
            PlayerKeydown=Keydown(press);
            switch (PlayerKeydown) {
                case Direction::up:     PlayerMove(Direction::up, RealMap, location);   break;
                case Direction::back:   PlayerMove(Direction::back, RealMap, location); break;
                case Direction::left:   PlayerMove(Direction::left, RealMap, location); break;
                case Direction::right:  PlayerMove(Direction::right, RealMap, location);break;
            }
            BotMove(RealMap,location);
            system("cls"); show(RealMap,TF,location);
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }
    system("cls");printf("You Lose!!!");system("pause");
    // 釋放動態記憶體 / releace dymantic memory
    for (short int i = 0; i < 8; i++) {delete[] RealMap[i];}delete[] RealMap;
    delete[] location;
    return 0;
}

inline void PlayerMove(Direction PlayerMovement, short int** RealMap, short int*location) {
    short int newX = location[0], newY = location[1];
    switch (PlayerMovement) {
        case Direction::up:     if(location[0]>0&&RealMap[location[0]-1][location[1]]!=2)   {newX = location[0] - 1;}break;
        case Direction::back:   if(location[0]<7&&RealMap[location[0]+1][location[1]]!=2)   {newX = location[0] + 1;}break;
        case Direction::left:   if(location[1]>0&&RealMap[location[0]][location[1]-1]!=2)   {newY = location[1] - 1;}break;
        case Direction::right:  if(location[1]<15&&RealMap[location[0]][location[1]+1]!=2)  {newY = location[1] + 1;}break;
    }
    if (newX != location[0] || newY != location[1]) {
        RealMap[location[0]][location[1]] = 0;
        RealMap[newX][newY] = 3;
        location[0] = newX; location[1] = newY;
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
//AI bot movement randomly / 隨機移動的人機
inline void BotMove(short int** RealMap, short int *location) {
    srand(time(NULL));
    short int movement; bool TF = 1;
    do {
        movement = rand() % 4 + 1;
        switch (movement) {
            case 1: if (location[2]>0 &&RealMap[location[2]-1][location[3]]!=2)     {TF=0;location[2]-=1;}break;
            case 2: if (location[2]<MapX-1&&RealMap[location[2]+1][location[3]]!=2) {TF=0;location[2]+=1;}break;
            case 3: if (location[3]>0 &&RealMap[location[2]][location[3]-1]!=2)     {TF=0;location[3]-=1;}break;
            case 4: if (location[3]<MapY-1&&RealMap[location[2]][location[3]+1]!=2) {TF=0;location[3]+=1;}break;
        }
    } while (TF);
}