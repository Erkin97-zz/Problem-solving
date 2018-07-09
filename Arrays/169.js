/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  var table = new Map();
  var maximum = {
    index : 0,
    value : 0
  };
  for (var i = 0; i < nums.length; i++) {
    if (table[nums[i]] == undefined){
      table[nums[i]] = 1;
    } else {
      table[nums[i]]++;
    }
    if (table[nums[i]] > maximum.value) {
      maximum.index = nums[i];
      maximum.value = table[nums[i]];
    }
  }
  return maximum.index;
};