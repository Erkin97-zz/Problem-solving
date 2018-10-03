/**
 * @param {string} S
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(S, shifts) {
  String.prototype.replaceAt=function(index, replacement) {
    return this.substr(0, index) + replacement+ this.substr(index + replacement.length);
  }
  var base = 26;
  var converted_array = [];
  for (var i = 0; i < S.length; i++) {
    converted_array[i] = S[i].charCodeAt(0) - 97;
  }
  for (var i = shifts.length - 1; i >= 0; i--){
    shifts[i] %= base;
    converted_array[i] += shifts[i];
    converted_array[i] %= base;
    if (i >= 0) shifts[i - 1] += shifts[i];
    S = S.replaceAt(i, String.fromCharCode(converted_array[i] + 97));
  }
  return S;
};