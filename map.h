#ifndef MAP_H
#define MAP_H

void load_map(int ROWS, int COLS, int arr[ROWS][COLS], int MAX_SIZE_BLOCK, int Y_GRID, int X_GRID, int grid_block[MAX_SIZE_BLOCK][MAX_SIZE_BLOCK]);
void print_map(int ROWS, int COLS, int map[ROWS][COLS]);

#endif