/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
  var help_tbl = [];
  var ans = 0;
  for (var i = 0; i < nums.length; i++) {
    var a = nums[i];
    if (a >= k) {
      if (help_tbl[a] != -1) {
        var b = a - k;
        if (help_tbl[b] != undefined) {
          ans++;
          help_tbl[a] = -1; 
        }
      }
    } else {
      var b = a + k;
      if (help_tbl[b] != undefined && help_tbl[b] != -1) {
        ans++;
        help_tbl[b] = -1;
      }
    }
    if (help_tbl[a] != -1) {
      help_tbl[a] = 1;
    }
  }
  return ans;
};