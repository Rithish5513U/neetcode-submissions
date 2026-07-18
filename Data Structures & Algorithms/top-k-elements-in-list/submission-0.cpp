class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        map<int, vector<int>> hello;
        for(auto& i : mp){
            hello[-i.second].push_back(i.first);
        }
        vector<int> ans;
        for(auto& i : hello){
            for(int num : i.second){
                if(k == 0) return ans;
                k--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};
