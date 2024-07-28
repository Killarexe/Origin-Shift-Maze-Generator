#include "maze.h"
#include <raylib.h>

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze Generator");

  Maze* maze = create_maze(16, 16);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    draw_maze(maze, 8);
    EndDrawing();
  }
  free_maze(maze);
  CloseWindow();
  return 0;
}
