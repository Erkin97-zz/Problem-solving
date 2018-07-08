/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums.sort(function(a, b){ return a-b; });
    var sum = 0, step = 0;
    for (var i = nums.length - 1; i >= 0; i--) {
        if (step == 1) sum += nums[i];
        step ^= 1;
    }
    return sum;
};