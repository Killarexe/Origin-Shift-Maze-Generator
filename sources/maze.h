#ifndef MAZE_H
#define MAZE_H


/*
 * Maze data format:
 * The maze data represents each cells(int value) as a 4-bit number,
 * and each bits on these numbers represents the directions.
 *
 * L: Left
 * R: Right
 * U: Up
 * D: Down
 * Format: 0bLRUD
 *
 * Exemple: 0b1010 This is a cell width the direction Left and Up.
 */

typedef struct Maze {
  int* maze_data;
  int width;
  int height;
} Maze;

Maze* create_maze(int width, int height);

void randomize_maze(Maze* maze, int iterations);

void draw_maze(Maze* maze, int size);

void free_maze(Maze* maze);

#endif
