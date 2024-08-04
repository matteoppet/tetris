#ifndef BLOCKS_H
#define BLOCKS_H

void load_block(int type_of_block, int state, int MAX_SIZE, int grid_block[MAX_SIZE][MAX_SIZE]);
void lock_block(int row, int col, int ROWS, int COLS, int MAX_SIZE, int map[ROWS][COLS], int grid_block[MAX_SIZE][MAX_SIZE]);

#endif