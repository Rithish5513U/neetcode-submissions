class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zero = 0;
        long long product = 1;
        for(int i : nums){
            if(i != 0) product *= i;
            else zero++;
        }
        vector<int> ans(n);
        if(zero > 1) return ans;
        else if(zero == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    ans[i] = product;
                    return ans;
                }
            }
        }
        for(int i = 0; i < n; i++){
            ans[i] = product / nums[i];
        }
        return ans;
    }
};
