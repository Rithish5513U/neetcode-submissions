class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string& s : strs){
            int size = s.size();
            string x = to_string(size);
            encoded += x;
            encoded += '#';
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int cnt = 0;
            string temp = "";
            while(s[i] != '#'){
                cnt = cnt * 10 + (s[i]-'0');
                i++;
            }
            i++;
            while(cnt--){
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
