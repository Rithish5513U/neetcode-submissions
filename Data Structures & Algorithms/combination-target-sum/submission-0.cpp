class Solution {
public:
    void dfs(int ind, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(ind == nums.size()){
            if(target == 0)
                ans.push_back(temp);
            return;
        }
        dfs(ind+1, nums, target, ans, temp);
        if(nums[ind] > target) return;
        temp.push_back(nums[ind]);
        dfs(ind, nums, target-nums[ind], ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, nums, target, ans, temp);
        return ans;
    }
};
