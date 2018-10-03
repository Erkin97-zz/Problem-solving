/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
  var n = nums.length, m = nums[0].length;
  if (r * c != n * m) {
    return nums;
  }
  var reshaped = [], counter = 0;
  for (var i = 0; i < r; i++){
    reshaped[i] = [];
    for (var j = 0; j < c; j++){
      reshaped[i].push(nums[Math.floor(counter / m)][counter % m]);
      counter++;
    }
  }
  return reshaped;
};