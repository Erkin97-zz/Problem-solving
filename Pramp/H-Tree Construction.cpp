#include <iostream>
void drawLine(int x1, int y1, int x2, int y2){
  // something
}
void drawHTree(int x, int y, int length, int depth){
  if (depth == 0) {
    return;
  }
  int x0 = x - length/2;
  int x1 = x + length/2;
  int y0 = y - length/2;
  int y1 = y + length/2;
  int newLength = length / 2;
  drawHTree(x0, y0, newLength, depth-1);
  drawHTree(x0, y1, newLength, depth-1);
  drawHTree(x1, y0, newLength, depth-1);
  drawHTree(x1, y1, newLength, depth-1);
}

int main()
{
  return 0;
}
