/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
  var x = 0, y = 0;
  for (var i = 0; i < moves.length; i++) {
      if (moves[i] == 'U') x++;
      else if (moves[i] == 'D') x--;
      else if (moves[i] == 'L') y++;
      else y--;
    }
    return (x==0) && (y==0);
};
