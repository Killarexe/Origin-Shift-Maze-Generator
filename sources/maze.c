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
  for(int i = 0; i < maze_size; i++) {
    int x = (i % maze->width) * size;
    int y = floor((double)i / (double)maze->width) * size;
    int cell = maze->maze_data[i];
    for (int x_offset = -1; x_offset < -2; x_offset++) {
      for (int y_offset = -1; y_offset < -2; y_offset++) {
        if (x_offset != y_offset && x_offset != 0) {
          int n_cell = maze->maze_data[i];
        }
      }
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->maze_data);
  free(maze);
}
