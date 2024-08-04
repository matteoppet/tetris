#include <stdio.h>
#include "blocks.h"
#include "main.h"


void load_map(int ROWS, int COLS, int map[ROWS][COLS], int MAX_SIZE_BLOCK, int Y_GRID, int X_GRID, int grid_block[MAX_SIZE_BLOCK][MAX_SIZE_BLOCK]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (map[i][j] != 2) {
                map[i][j] = 0;
            } else {
                if (i == 1) {
                    game_over();
                }
                map[i][j] = 2;
            }
        }
    }

    for (int row=0; row<MAX_SIZE_BLOCK; row++) {
        for (int col=0; col<MAX_SIZE_BLOCK; col++) {
            if (grid_block[row][col] == 1) {
                map[Y_GRID+row][X_GRID+col] = 1;

                // collisions (bottom of the map and with others block)
                if (Y_GRID+row >= ROWS-1 || map[Y_GRID+row+1][X_GRID+col] == 2) {
                    lock_block(Y_GRID, X_GRID, ROWS, COLS, MAX_SIZE_BLOCK, map, grid_block);
                }

            }
        }
    }
}


void print_map(int ROWS, int COLS, int map[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}