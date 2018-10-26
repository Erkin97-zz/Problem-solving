class Solution {
public:
    bool if_self(int a) {
        int b = a;
        while (a > 0) {
            if (a % 10 == 0) return false;
            if (b % (a % 10) != 0) return false;
            a /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> v;
        while(left<=right){
            if(if_self(left)) v.push_back(left);
            left++;
        }
        return v;
    }
};