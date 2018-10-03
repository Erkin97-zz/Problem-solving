/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
  var B = [];
  for (var i = 0; i < A.length; i++) {
    B[i] = [];
    for (var j = A[i].length - 1; j >= 0; j--) {
      B[i].push(A[i][j]^1);
    }
  }
  return B;
};