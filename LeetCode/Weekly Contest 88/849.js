/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
  var previous = -1;
  var ans = 0;
  for (var  i = 0; i < seats.length; i++) {
    if (seats[i] == 1) {
      if (previous == -1){
        ans = Math.max(ans, i);
      } else {
        ans = Math.max(ans, Math.floor((i - previous)/2));
      }
      previous = i;
    }
  }
  i--;
  if (seats[i] == 0) {
    ans = Math.max(i - previous, ans);
  }
  return ans;
};