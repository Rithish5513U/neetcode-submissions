class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int r = 1 & (n >> i);
            ans |= (r << (31 - i));
        }
        return ans;
    }
};
