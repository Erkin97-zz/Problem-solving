class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string decode[] = {
                        ".-","-...","-.-.","-..",".","..-.","--.",
                        "....","..",".---","-.-",".-..","--","-.",
                        "---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--.."};
        int base = 97; // ascii code of a is 97;
        set <string> h_set;
        string decoded_word = "";
        for (int i = 0; i < words.size(); i++) {
            decoded_word = "";
            for (int j = 0; j < words[i].length(); j++) {
                decoded_word += decode[int(words[i][j]) - 97];
            }
            h_set.insert(decoded_word);
        }
        return h_set.size();
    }
};