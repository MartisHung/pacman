#include <stdio.h>
int** map(int** area) {
    area[0][0] = 2; area[0][1] = 2; area[0][2] = 2; area[0][3] = 2; area[0][4] = 2; area[0][5] = 2; area[0][6] = 2; area[0][7] = 2;
    area[0][8] = 2; area[0][9] = 2; area[0][10] = 2; area[0][11] = 2; area[0][12] = 2; area[0][13] = 2; area[0][14] = 2; area[0][15] = 2;
    area[1][0] = 2; area[1][1] = 1; area[1][2] = 1; area[1][3] = 1; area[1][4] = 1; area[1][5] = 1; area[1][6] = 1; area[1][7] = 1;
    area[1][8] = 1; area[1][9] = 1; area[1][10] = 1; area[1][11] = 1; area[1][12] = 1; area[1][13] = 1; area[1][14] = 1; area[1][15] = 2;
    area[2][0] = 2; area[2][1] = 1; area[2][2] = 1; area[2][3] = 2; area[2][4] = 2; area[2][5] = 2; area[2][6] = 2; area[2][7] = 1;
    area[2][8] = 1; area[2][9] = 2; area[2][10] = 2; area[2][11] = 2; area[2][12] = 2; area[2][13] = 1; area[2][14] = 1; area[2][15] = 2;
    area[3][0] = 2; area[3][1] = 1; area[3][2] = 1; area[3][3] = 1; area[3][4] = 1; area[3][5] = 1; area[3][6] = 1; area[3][7] = 1;
    area[3][8] = 1; area[3][9] = 1; area[3][10] = 1; area[3][11] = 1; area[3][12] = 1; area[3][13] = 1; area[3][14] = 1; area[3][15] = 2;
    area[4][0] = 2; area[4][1] = 1; area[4][2] = 1; area[4][3] = 1; area[4][4] = 2; area[4][5] = 2; area[4][6] = 1; area[4][7] = 1;
    area[4][8] = 1; area[4][9] = 1; area[4][10] = 1; area[4][11] = 2; area[4][12] = 2; area[4][13] = 1; area[4][14] = 1; area[4][15] = 2;
    area[5][0] = 2; area[5][1] = 1; area[5][2] = 2; area[5][3] = 2; area[5][4] = 2; area[5][5] = 2; area[5][6] = 2; area[5][7] = 2;
    area[5][8] = 2; area[5][9] = 2; area[5][10] = 2; area[5][11] = 2; area[5][12] = 2; area[5][13] = 2; area[5][14] = 1; area[5][15] = 2;
    area[6][0] = 2; area[6][1] = 1; area[6][2] = 1; area[6][3] = 1; area[6][4] = 1; area[6][5] = 1; area[6][6] = 1; area[6][7] = 1;
    area[6][8] = 1; area[6][9] = 1; area[6][10] = 1; area[6][11] = 1; area[6][12] = 1; area[6][13] = 1; area[6][14] = 1; area[6][15] = 2;
    area[7][0] = 2; area[7][1] = 2; area[7][2] = 2; area[7][3] = 2; area[7][4] = 2; area[7][5] = 2; area[7][6] = 2; area[7][7] = 2;
    area[7][8] = 2; area[7][9] = 2; area[7][10] = 2; area[7][11] = 2; area[7][12] = 2; area[7][13] = 2; area[7][14] = 2; area[7][15] = 2;
    return area;
}
inline void show(int** RealMap) {
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
}