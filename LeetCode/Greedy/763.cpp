class Solution {
public:
    vector<int> partitionLabels(string S) {
        int l_ap[1000]; // first and last appearance
        vector <int> ans;
        string buffer = "";
        for (int i = 0; i < S.length(); i++) {
            l_ap[int(S[i])] = i;
        }
        int last_index = -1;
        for (int i = 0; i < S.length(); i++) {
            buffer += S[i];
            last_index = max(last_index, l_ap[int(S[i])]);
            if (last_index == i) {
                ans.push_back(buffer.length());
                buffer = "";
                last_index = -1;
            }
        }
        return ans;
    }
};