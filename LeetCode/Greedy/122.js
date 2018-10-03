/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if (prices.length == 0) return 0;
  var minimum_outcome = prices[0];
  var maximum_outcome = prices[0];
  var ans = 0;
  for (var i = 1; i < prices.length; i++) {
    if (prices[i] < maximum_outcome) {
  //    console.log(maximum_outcome + " " + minimum_outcome);
      ans += maximum_outcome - minimum_outcome;
      maximum_outcome = prices[i];
      minimum_outcome = prices[i];
    }
    maximum_outcome = Math.max(maximum_outcome, prices[i]);
  }
  ans += maximum_outcome - minimum_outcome;
  return ans;
};

var test = [7,6,4,3,1];
console.log(maxProfit(test));