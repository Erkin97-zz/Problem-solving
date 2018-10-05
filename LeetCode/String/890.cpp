class Solution {
public:
    vector <int> decode_pattern(string word) {
        unordered_map<char, int> h_table;
        int counter = 1;
        vector <int > decoded_pattern;
        for (int i = 0; i < word.length(); i++) {
            if (h_table[word[i]] == 0) {
                h_table[word[i]] = counter;
                counter++;
            }
            decoded_pattern.push_back(h_table[word[i]]);
        }
        return decoded_pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, int> h_table;
        vector <int> decoded_pattern = decode_pattern(pattern);
        vector <string> res;
        for (int i = 0; i < words.size(); i++) {
            if (decode_pattern(words[i]) == decoded_pattern) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};