/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
  if (k < 0) return 0; // exception
  var used = [], exists = [];
  var ans = 0;
  for (var i = 0; i < nums.length; i++) {
    if (exists[nums[i]] == undefined) {
      exists[nums[i]] = 1;
    }
    else {
      exists[nums[i]]++;
    }
  }
  for (var i = 0; i < nums.length; i++) {
    if (used[nums[i]] != 1) {
      exists[nums[i]]--;
      if (exists[nums[i] + k] >= 1) {
        ans++;
      }
      exists[nums[i]]++;
      used[nums[i]] = 1;
    }
  }
  return ans;
};

var nums = [1,1,1,1,1];
var k = 0;
console.log(findPairs(nums, k));