class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0, counter = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                counter ++;
            } else {
                counter --;
                if (counter < 0) {
                    counter = 0;
                    ans ++;
                }
            }
        }
        ans += counter;
        return ans;
    }
};