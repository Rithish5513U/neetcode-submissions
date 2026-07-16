class Solution {
public:
    bool contains[26];
    pair<int, int> order(string& a, string& b){
        pair<int, int> p;
        for(int i = 0; i < min(a.size(), b.size()); i++){
            if(a[i] != b[i]){
                int x = a[i] - 'a', y = b[i] - 'a';
                return {x, y};
            }
        }
        return {-1, -1};
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        memset(contains, false, sizeof(contains));
        for(int i = 0; i < n; i++){
            for(char c : words[i]){
                contains[c-'a'] = true;
            }
        }
        vector<vector<int>> edges(26);
        int inDegree[26] = {0};
        queue<int> q;
        string s = "";
        for(int i = 1; i < n; i++){
            pair<int, int> p = order(words[i-1], words[i]);
            if(p.first != -1){
                edges[p.first].push_back(p.second);
                inDegree[p.second]++;
            }
            else{
                if(words[i-1].size() > words[i].size()) return "";
            }
        }
        for(int i = 0; i < 26; i++){
            if(contains[i] && inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            char c = x + 'a';
            s += c;
            for(auto it : edges[x]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(contains[i] && inDegree[i] > 0){
                return "";
            }
        }
        return s;
    }
};
