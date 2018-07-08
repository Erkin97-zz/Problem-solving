/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
  /**
   * @param {number} x 
   * @param {number} y
   * @returns {number} 
   */
  var dfs = function(x, y){
    if (grid[x][y] == 0) return 0;
    grid[x][y] = 0;
    var sum = 1;
    if (x + 1 < grid.length) sum += dfs(x + 1, y);
    if (x - 1 >= 0) sum += dfs(x - 1, y);
    if (y + 1 < grid[i].length) sum += dfs(x, y + 1);
    if (y - 1 >= 0) sum += dfs(x, y - 1);
    return sum;
  };
  var max = 0;
  for (var i = 0; i < grid.length; i++){
    for (var j = 0; j < grid[i].length; j++){
      if (grid[i][j] == 1){
        max = Math.max(dfs(i, j), max);
      }
    }
  }
  return max;
};