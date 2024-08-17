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
  maze->origin_index = 0;
  return maze;
}

void move_origin(Maze* maze, int direction) {
  if (direction == 0) {
    return;
  }
  int origin_x = maze->origin_index % maze->width;
  int origin_y = floor((double)maze->origin_index / (double)maze->width); 
  if (IS_DOWN(direction)) {
    origin_y += 1;
  }
  if (IS_UP(direction)) {
    origin_y -= 1;
  }
  if (IS_RIGHT(direction)) {
    origin_x += 1;
  }
  if (IS_LEFT(direction)) {
    origin_x -= 1;
  }
  if (origin_x < 0 || origin_x >= maze->width || origin_y < 0 || origin_y >= maze->height) {
    return;
  }
  int new_origin_index = origin_y * maze->width + origin_x;
  maze->maze_data[maze->origin_index] = direction;
  maze->maze_data[new_origin_index] = 0;
  maze->origin_index = new_origin_index;
}

void randomize_maze(Maze* maze, int iterations) {
  for (int i = 0; i < iterations; i++) {
    int power = GetRandomValue(0, 3);
    int direction = pow(2, power);
    move_origin(maze, direction);
  }
}

void draw_maze(Maze *maze, int size) {
  int maze_size = maze->width * maze->height;
  int half_size = size / 2;
  for(int i = 0; i < maze_size; i++) {
    int x_node = i % maze->width;
    int y_node = floor((double)i / (double)maze->width);
    int x_pos = x_node * size + half_size;
    int y_pos = y_node * size + half_size;
    int node = maze->maze_data[i];
    if (node == 0) {
      DrawRectangle(x_pos - half_size / 4, y_pos - half_size / 4, half_size / 2, half_size / 2, PINK);
    } else {
      DrawRectangle(x_pos - half_size / 8, y_pos - half_size / 8, half_size / 4, half_size / 4, PURPLE);
    }
    if (IS_DOWN(node)) {
      DrawLine(x_pos, y_pos, x_pos, y_pos + size, RED);
    }
    if (IS_UP(node)) {
      DrawLine(x_pos, y_pos, x_pos, y_pos - size, BLUE);
    }
    if (IS_RIGHT(node)) {
      DrawLine(x_pos, y_pos, x_pos + size, y_pos, GREEN);
    }
    if (IS_LEFT(node)) {
      DrawLine(x_pos, y_pos, x_pos - size, y_pos, YELLOW);
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->maze_data);
  free(maze);
}
