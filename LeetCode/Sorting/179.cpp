class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> str_nums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            str_nums[i] = to_string(nums[i]);
        }
        string ans = "";
        sort(str_nums.begin(), str_nums.end(), [](string &a, string &b){
            return (a + b) > (b + a);
        });
        for (int i = 0; i < str_nums.size(); i++) {
            ans += str_nums[i];
        }
        while(ans[0] == '0' && ans.size() > 1) ans.erase(ans.begin());
        return ans;
    }
};