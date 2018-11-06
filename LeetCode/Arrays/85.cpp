class Solution {
public:
    int area(vector<vector<char>>& matrix, int x1, int y1, int x2, int y2) {
        int area = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (matrix[i][j] == '0') {
                    return 0;
                } else {
                    area ++;
                }
            }
        }
        return area;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maximum_area = 0;
        for (int x1 = 0; x1 < matrix.size(); x1++) {
            for (int y1 = 0; y1 < matrix[x1].size(); y1++) {
                int x2 = x1, y2 = y1;
                while (x2 != matrix.size() && y2 != matrix[x2].size()) {
                    maximum_area = max(maximum_area, area(matrix, x1, y1, x2, y2));
                    x2++, y2++;
                }
            }
        }
        return maximum_area;
    }
};