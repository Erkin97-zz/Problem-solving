/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
	var helper_string = "", res = "";
	var step = 	0, timer = 0;
	for (var i = 0; i <= s.length; i++) {
		if (timer == k || i == s.length) {
			res += helper_string;
			helper_string = "";
			step ^= 1;
			timer = 0;
			if (i == s.length) break;
		}
		if (step%2 == 0) {
			helper_string = s[i] + helper_string;
		} else {
			helper_string += s[i];
		}
		timer++;
	}
	return res;
};