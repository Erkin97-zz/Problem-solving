class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0, tp;
        int maximum_area = 0, rect_area;
        stack <int> st;
        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i++);
            } else {
                tp = st.top();
                st.pop();
                rect_area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
                maximum_area = max(maximum_area, rect_area);
            }
        }
        while (!st.empty()) {
            tp = st.top();
            st.pop();
            rect_area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            maximum_area = max(maximum_area, rect_area);
        }
        return maximum_area;
    }
};