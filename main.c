#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "map.h"
#include "blocks.h"

#define MAP_ROWS 20
#define MAP_COLS 10
#define MAX_BLOCKS_SIZE 4
#define TOTAL_BLOCKS 5


int map[MAP_ROWS][MAP_COLS];
int grid_block[MAX_BLOCKS_SIZE][MAX_BLOCKS_SIZE];

int Y_GRID_BLOCK = 0;
int X_GRID_BLOCK = 0;
int TYPE_OF_BLOCK = 1;
int STATE = 1;

int run = 0;
int remove_line;
int row_to_remove;
int POINTS;


// functions in map.h
void load_map(int ROWS, int COLS, int map[ROWS][COLS], int MAX_SIZE_BLOCK, int Y_GRID, int X_GRID, int grid_block[MAX_SIZE_BLOCK][MAX_SIZE_BLOCK]);
void print_map(int ROWS, int COLS, int map[ROWS][COLS]);

// functions in blocks.h
void load_block(int type_of_block, int state, int MAX_SIZE, int grid_block[MAX_SIZE][MAX_SIZE]);

// functions in this file
void handle_input_user();
void waitFor(unsigned int secs);
void check_fill_lines();
void remove_and_shift(int index_to_remove);


int main() {
    printf("Press any key to start..");

    int c = getch();

    waitFor(1);
    
    // game loop
    system("cls");
    while (run == 0) {
        printf("\e[?25l");

        handle_input_user();

        load_block(TYPE_OF_BLOCK, STATE, MAX_BLOCKS_SIZE, grid_block);
        load_map(MAP_ROWS, MAP_COLS, map, MAX_BLOCKS_SIZE, Y_GRID_BLOCK, X_GRID_BLOCK, grid_block);

        check_fill_lines();

        print_map(MAP_ROWS, MAP_COLS, map);

        if (remove_line == 1) {
            waitFor(1);

            remove_and_shift(row_to_remove);

            remove_line = 0;
            row_to_remove = 0;
        }

        printf("\nPoints: %d\n", POINTS);

        printf("\e[%iA", MAP_ROWS+2);
        
        Y_GRID_BLOCK++;
        waitFor(1);
    }

    // when the game ends
    system("cls");
    printf("\e[%iA", MAP_ROWS+2);
    printf("Game over, you lost.. Points reached: %d\n\n", POINTS);

    print_map(MAP_ROWS, MAP_COLS, map);

    return 0;
}


void handle_input_user() {
    if (_kbhit()) {
        int c = getch();

        switch (c) {
            case 97: // a key = move left
                X_GRID_BLOCK--;
                break;
            case 115: // s key = move right
                X_GRID_BLOCK++;
                break;
            case 100: // d key = rotate
                STATE++;
                if (STATE == 4) {
                    STATE = 1;
                }
                break;
        }
    }
}


void waitFor(unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);               
}


void reset() {
    POINTS++;

    for (int row=0; row<MAX_BLOCKS_SIZE; row++) {
        for (int col=0; col<MAX_BLOCKS_SIZE; col++) {
            grid_block[row][col] = 0;
        }
    }

    Y_GRID_BLOCK = 0;
    X_GRID_BLOCK = 0;

    do {
        TYPE_OF_BLOCK = rand() % 5;
    } while (TYPE_OF_BLOCK == 0);

    STATE = 1;
}


void check_fill_lines() {
    for (int row=0; row<MAP_ROWS; row++) {
        int count_blocks = 0;

        for (int col=0; col<MAP_COLS; col++) {
            if (map[row][col] == 2) {
                count_blocks++;
            }
        }

        if (count_blocks == MAP_COLS) {
            for (int col_filled=0; col_filled<MAP_COLS; col_filled++) {
                map[row][col_filled] = 3;
            }

            remove_line = 1;
            row_to_remove = row;
        }
    }
}


void remove_and_shift(int index_to_remove) {
    // Shift rows to the left from index_to_remove
    for (int i = index_to_remove; i < MAP_ROWS - 1; i++) {
        memcpy(map[i], map[i + 1], MAP_COLS * sizeof(int));
    }

    // Add a new row of zeros at the start
    int new_row[MAP_COLS] = {0};
    for (int i = MAP_ROWS - 1; i > 0; i--) {
        memcpy(map[i], map[i - 1], MAP_COLS * sizeof(int));
    }
    memcpy(map[0], new_row, MAP_COLS * sizeof(int));
}


void game_over() {
    run = 1;
}
