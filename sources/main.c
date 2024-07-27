#include <raylib.h>

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze Generator");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
