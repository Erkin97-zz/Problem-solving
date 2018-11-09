class Solution {
public:
    string addStrings(string num1, string num2) {
        int base = 10;
        int k = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        for (size_t i = 0; i < max(num1.size(), num2.size()); i++) {
            int a = i < num1.size() ? int(num1[i] - 48) : 0;
            int b = i < num2.size() ? int(num2[i] - 48) : 0;
            k += a + b;
            ans += char((k % 10) + 48);
            k /= 10;
        }
        if (k > 0) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};