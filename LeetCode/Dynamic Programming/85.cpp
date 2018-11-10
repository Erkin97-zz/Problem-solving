class Solution {
public:
    int maximalRectangleHist(vector<int>& heights) {
        int maximum_area = 0, area;
        int i = 0, tp;
        stack <int> st;
        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i++);
            } else {
                tp = st.top();
                st.pop();
                area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
                maximum_area = max(area, maximum_area);
            }
        }
        while (!st.empty()) {
            tp = st.top();
            st.pop();
            area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            maximum_area = max(area, maximum_area);
        }
        return maximum_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector <vector <int> > hist2d(matrix.size());
        int maximum_area = 0;
        for (int i = 0; i < matrix.size(); i++) {
            hist2d[i].resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    hist2d[i][j] = i == 0 ? 1 : hist2d[i - 1][j] + 1;
                    maximum_area = max(maximum_area, hist2d[i][j]);
                } else {
                    hist2d[i][j] = 0;
                }
            }
        }
        for (int  i = 0; i < hist2d.size(); i++) {
            maximum_area = max(maximum_area, 
                               maximalRectangleHist(hist2d[i]));
        }
        return maximum_area;
    }
};