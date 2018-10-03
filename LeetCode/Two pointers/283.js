/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  for (var l = 0, r = 0; l < nums.length; l++) {
   if (nums[l] != 0) {
     var tmp = nums[l];
     nums[l]=nums[r];
     nums[r]=tmp;
     r++;
   }
  }
};