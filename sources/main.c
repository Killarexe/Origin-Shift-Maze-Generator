#include "maze.h"
#include <math.h>
#include <raylib.h>

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720
#define MAZE_UPDATE_FREQ 1000.0f

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze Generator");

  int primary_screen = GetCurrentMonitor();
  int screen_width = GetMonitorWidth(primary_screen);
  int screen_height = GetMonitorHeight(primary_screen);
  Vector2 screen_pos = GetMonitorPosition(primary_screen);
  int window_x = screen_width / 2 - WINDOW_WIDTH / 2 + (int)screen_pos.x;
  int window_y = screen_height / 2 - WINDOW_HEIGHT / 2 + (int)screen_pos.y;
  SetWindowPosition(window_x, window_y);

  Maze* maze = create_maze(16, 16);
  float frequency = 1.0f / MAZE_UPDATE_FREQ;
  float current_time = 0.0f;
  while (!WindowShouldClose()) {
    float delta = GetFrameTime();
    if (current_time >= frequency) {
      int power = GetRandomValue(0, 3);
      int direction = pow(2, power);
      move_origin(maze, direction);
      current_time = 0;
    } else {
      current_time += delta;
    }
    BeginDrawing();
    ClearBackground(BLACK);
    draw_maze(maze, WINDOW_WIDTH / 16);
    EndDrawing();
  }
  free_maze(maze);
  CloseWindow();
  return 0;
}
