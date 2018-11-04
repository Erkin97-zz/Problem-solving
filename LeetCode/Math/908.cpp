class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int ans = 0;
        sort(A.begin(), A.end());
        int smallest = A[0], maximum = A[A.size() - 1];
        ans = maximum - smallest;
        ans -= 2*K;
        if (ans < 0) ans = 0;
        return ans;
    }
};