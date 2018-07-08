/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
  var max = 0, sum = 0;
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] == 1) {
      sum ++;
      max = Math.max(max, sum);
    } else {
      sum = 0;
    }
  }
  return max;
};