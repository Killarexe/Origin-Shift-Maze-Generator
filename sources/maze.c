#include "maze.h"
#include <math.h>
#include <stdlib.h>
#include <raylib.h>

Maze* create_maze(int width, int height) {
  Maze* maze = malloc(sizeof(struct Maze));
  maze->width = width;
  maze->height = height;
  int maze_size = width * height;
  int maze_data[maze_size];
  maze_data[0] = 0;
  for (int i = 1; i < maze_size; i++) {
    int x = i % width;
    if (x == 0) {
      maze_data[i] = 0x1; 
    } else {
      maze_data[i] = 0x8;
    }
  }
  maze->maze_data = maze_data;
  return maze;
}

void draw_maze(Maze *maze, int size) {
  int maze_size = maze->width * maze->height;
  for(int i = 0; i < maze_size; i++) {
    int x = (i % maze->width) * size;
    int y = floor((double)i / (double)maze->width) * size;
    int cell = maze->maze_data[i];
    if ((cell & 0x1) == 0) {
      DrawLine(x, y - size, x + size, y - size, WHITE);
    }
    if ((cell & 0x2) == 0) {
      DrawLine(x, y + size, x + size, y + size, WHITE);
    }
    if ((cell & 0x4) == 0) {
      DrawLine(x + size, y, x + size, y + size, WHITE);
    }
    if ((cell & 0x8) == 0) {
      DrawLine(x, y, x, y + size, WHITE);
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->maze_data);
  free(maze);
}
