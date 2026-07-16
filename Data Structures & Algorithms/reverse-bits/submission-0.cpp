class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int r = (n & (1 << i)) ? 1 : 0;
            ans |= (r << (31 - i));
        }
        return ans;
    }
};
