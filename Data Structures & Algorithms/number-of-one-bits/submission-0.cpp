class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            int r = n % 2;
            n /= 2;
            ans += r;
        }
        return ans;
    }
};
