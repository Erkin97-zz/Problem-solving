class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = 0;
        while (x > 0 || y > 0) {
            sum += (x & 1) != (y & 1);
            x = x >> 1;
            y = y >> 1;
        }    
        return sum;
    }
};