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

int get_node(Maze* maze, int x, int y) {
  int index = y * maze->width + x;
  if (index < (maze->width * maze->height)) {
    return maze->maze_data[index];
  }
  return 0;
}

void draw_maze(Maze *maze, int size) {
  int maze_size = maze->width * maze->height;
  for(int i = 0; i < maze_size; i++) {
    int x_node = (i % maze->width);
    int y_node = floor((double)i / (double)maze->width);
    int x_pos = x_node * size;
    int y_pos = y_node * size;
    int node = maze->maze_data[i];
    if (node == 0x2) {
      if (get_node(maze, x_node - 1, y_node) != 0x4) {
        DrawLine(x_pos, y_pos, x_pos, y_pos + size, WHITE);
      }
      if (get_node(maze, x_node + 1, y_node) != 0x8) {
        DrawLine(x_pos + size, y_pos, x_pos + size, y_pos + size, WHITE);
      }
    } else if (node == 0x8) {
      DrawLine(x_pos, y_pos + size, x_pos + size, y_pos + size, WHITE);
      DrawLine(x_pos, y_pos, x_pos + size, y_pos, WHITE);
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->maze_data);
  free(maze);
}
