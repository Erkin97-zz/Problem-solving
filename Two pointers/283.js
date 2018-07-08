/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  var sum_zeros = 0;
  var sum_non_zeros = 0;
  for (var i = 0; i < nums.length; i++) {
    if (nums[i] == 0) {
      sum_zeros ++;
    } else {
      nums[sum_non_zeros++] = nums[i];
    }
  }
  for (var i = 0; i < sum_zeros; i++) {
    nums [nums.length - i - 1] = 0; 
  }
  return nums;
};