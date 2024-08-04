#include <stdio.h>
#include <string.h>
#include "main.h"


void load_block(int type_of_block, int state, int MAX_SIZE, int grid_block[MAX_SIZE][MAX_SIZE]) {
    memset(grid_block, 0, sizeof(grid_block[0][0]) * MAX_SIZE * MAX_SIZE); // faster way to zero out the grid block array

    switch (type_of_block) {
        case 1: // i-block
            switch (state) {
                case 1:
                    grid_block[0][0] = 1;
                    grid_block[0][1] = 1;
                    grid_block[0][2] = 1;
                    grid_block[0][3] = 1;
                    break;
                case 2:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[2][0] = 1;
                    grid_block[3][0] = 1;
                    break;
                case 3: 
                    grid_block[0][0] = 1;
                    grid_block[0][1] = 1;
                    grid_block[0][2] = 1;
                    grid_block[0][3] = 1;
                    break;
                case 4:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[2][0] = 1;
                    grid_block[3][0] = 1;
                    break;
            }
            break;
        case 2: // square-block
            switch (state) {
                case 1 ... 4:
                    grid_block[0][0] = 1;
                    grid_block[0][1] = 1;
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    break;
            }
            break;
        case 3: // L-block
            switch (state) {
                case 1:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[2][0] = 1;
                    grid_block[1][1] = 1;
                    break;
                case 2:
                    grid_block[1][0] = 1;
                    grid_block[0][0] = 1;
                    grid_block[0][2] = 1;
                    grid_block[0][3] = 1;
                    break;
                case 3:
                    grid_block[0][0] = 1;
                    grid_block[0][1] = 1;
                    grid_block[1][1] = 1;
                    grid_block[1][2] = 1;
                    break;
                case 4:
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    grid_block[1][2] = 1;
                    grid_block[0][2] = 1;
                    break;
            }
            break;
        case 4:
            switch (state) {
                case 1:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    grid_block[2][1] = 1;
                    break;
                case 2:
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    grid_block[0][1] = 1;
                    grid_block[0][2] = 1;
                    break;
                case 3:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    grid_block[2][1] = 1;
                    break;
                case 4:
                    grid_block[1][0] = 1;
                    grid_block[1][1] = 1;
                    grid_block[0][1] = 1;
                    grid_block[0][2] = 1;
                    break;
            }
            break;
        case 5:
            switch (state) {
                case 1:
                    grid_block[0][0] = 1;
                    grid_block[0][1] = 1;
                    grid_block[0][2] = 1;
                    grid_block[1][1] = 1;
                    break;
                case 2:
                    grid_block[1][1] = 1;
                    grid_block[0][1] = 1;
                    grid_block[1][1] = 1;
                    grid_block[2][1] = 1;
                    break;
                case 3:
                    grid_block[1][1] = 1;
                    grid_block[0][1] = 1;
                    grid_block[1][1] = 1;
                    grid_block[1][2] = 1;
                    break;
                case 4:
                    grid_block[0][0] = 1;
                    grid_block[1][0] = 1;
                    grid_block[2][0] = 1;
                    grid_block[1][1] = 1;
                    break;
            }
            break;
    }
}


void lock_block(int row, int col, int ROWS, int COLS, int MAX_SIZE, int map[ROWS][COLS], int grid_block[MAX_SIZE][MAX_SIZE]) {
    int position_each_block[4][2];
    int count = 0;
    
    for (int r=0; r<MAX_SIZE; r++) {
        for (int c=0; c<MAX_SIZE; c++) {
            if (grid_block[r][c] == 1) {
                position_each_block[count][0] = row+r;
                position_each_block[count][1] = col+c;
                count++;
            }
        }
    }

    for (int index=0; index<sizeof(position_each_block)/sizeof(position_each_block[0]); index++) {
        map[position_each_block[index][0]][position_each_block[index][1]] = 2;
    }

    reset();
}