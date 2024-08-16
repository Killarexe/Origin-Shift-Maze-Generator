#include "maze.h"

#include <math.h>
#include <stdlib.h>
#include <raylib.h>

Maze* create_maze(int width, int height) {
  Maze* maze = malloc(sizeof(struct Maze));
  int maze_size = width * height;
  int* maze_data = malloc(sizeof(int) * maze_size);
  maze_data[0] = 0;
  for (int i = 1; i < maze_size; i++) {
    int x = i % width;
    if (x == 0) {
      maze_data[i] = 0x2; 
    } else {
      maze_data[i] = 0x8;
    }
  }

  maze->width = width;
  maze->height = height;
  maze->maze_data = maze_data;
  return maze;
}

void draw_maze(Maze *maze, int size) {
  int maze_size = maze->width * maze->height;
  int half_size = size / 2;
  for(int i = 0; i < maze_size; i++) {
    int x_node = (i % maze->width);
    int y_node = floor((double)i / (double)maze->width);
    int x_pos = x_node * size - half_size;
    int y_pos = y_node * size - half_size;
    int node = maze->maze_data[i];
    if (node == 0) {
      DrawRectangle(x_pos + half_size / 2, y_pos + half_size / 2, half_size / 2, half_size / 2, WHITE);
    }
    if ((node & 1) == 1) {
      DrawLine(x_pos, y_pos, x_pos, y_pos + half_size, BLUE);
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->maze_data);
  free(maze);
}
