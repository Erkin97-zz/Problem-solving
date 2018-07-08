/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
  var lengthArray = A.length;
  var B = [];
  for (var i = 0; i < A[0].length; i++) {
    B[i] = [];
    for (var j = 0; j < A.length; j++) {
      B[i].push(A[j][i]);
    }
  }
  return B;
};