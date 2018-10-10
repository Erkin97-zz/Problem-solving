#include <iostream>
#include <vector>

using namespace std;
int x_moves[] = {0, 1, 0, -1};
int y_moves[] = {1, 0, -1, 0};
vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  int direction = 0; // left
  int i = 0, j = 0, counter = 0;
  int n = inputMatrix.size(), m = inputMatrix[0].size();
  vector <int> answer;
  int left_border = 0, right_border = m, up_border = 0, bottom_border = n;
  while(counter != n * m) {
    answer.push_back(inputMatrix[i][j]);
    counter++;
    if(i+x_moves[direction] == bottom_border || 
       i+x_moves[direction] < up_border  || 
       inputMatrix[i+x_moves[direction]][j] == -1) { // hit border
      direction++;
      direction%=4;
    } else if(j + y_moves[direction] == right_border || 
              j + y_moves[direction] < left_border  || 
              inputMatrix[i][j+y_moves[direction]] == -1) {
      if (direction == 0) {
        up_border++;
      } else if (direction == 1){
        right_border--;
      } else if (direction == 2){
        bottom_border--;
      } else if (direction == 3){
        left_border++;
      }
       direction++;
       direction %= 4;
    }
    if (counter == n*m) break;
    i += x_moves[direction];
    j += y_moves[direction];  
  }
  return answer;
}

int main() {
  return 0;
}