/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
	for (var k = 0; k < matrix.length; k++){
		for (var l = 0; l < matrix[0].length; l++ ) {
			var i = k, j = l;
			while (true) {
				if (i + 1 == matrix.length || k + 1 == matrix[0].length) break;
				if (matrix[i+1][j+1] != matrix[i][j]) return false;
				i++;
				j++;
			}
		}
	}
	return true;
};