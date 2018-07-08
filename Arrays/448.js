/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
  for (var i = 0; i < nums.length; i++) {
    if (nums[Math.abs(nums[i]) - 1] > 0)
      nums[Math.abs(nums[i]) - 1] *= -1;
  }
  var missings = [];
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] > 0)
      missings.push(i + 1);
  }
  return missings;
};