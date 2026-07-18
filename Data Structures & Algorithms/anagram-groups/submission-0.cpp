class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(string& s : strs){
            vector<int> cnt(26);
            for(char& c : s){
                cnt[c-'a']++;
            }
            mp[cnt].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& v : mp){
            ans.push_back(v.second);
        }
        return ans;
    }
};
