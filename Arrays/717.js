/**
 * @param {number[]} bits
 * @return {boolean}
 */
var isOneBitCharacter = function(bits) {
  if (bits[bits.length - 1] != 0)
    return false;
  var sum_zeros = 0, sum_ones = 0;
  for (var i = 0; i < bits.length - 2; i++) {
    if (bits[i]) {
      bits[i+1] = 0;
      bits[i]=0;
    }
  }
  for (var i = 0; i < bits.length; i++) {
    if (bits[i]) {
      return false;
    }
  }
  return true;
};