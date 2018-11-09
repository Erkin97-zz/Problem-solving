class Solution {
public:
    string multiply(string num1, string num2) {
        vector <int> ans(num1.size() + num2.size(), 0); // convert into string later
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                ans[i+j] += int(num1[i] - 48) * int(num2[j] - 48);
            }
        }
        for (int i = 0; i < ans.size() - 1; i++) {
            ans[i + 1] += (ans[i] / 10);
            ans[i] %= 10;
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans[0] == 0) ans.erase(ans.begin());
        string str_ans = "";
        for (int i = 0; i < ans.size(); i++) {
            str_ans += char(ans[i] + 48);
        }
        return str_ans;
    }
};