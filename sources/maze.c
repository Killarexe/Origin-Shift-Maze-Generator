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
    int y = floor((double)i / (double)width);
    if (x == 0) {
      maze_data[i] = 0b0001; 
    } else {
      maze_data[i] = 0b1000;
    }
  }
  maze->maze_data = maze_data;
  return maze;
}


void draw_maze(Maze *maze) {
  int maze_size = maze->width * maze->height;
  for(int i = 0; i < maze_size; i++) {
    int x = i % maze->width;
    int y = floor((double)i / (double)maze->width);
  }
}
