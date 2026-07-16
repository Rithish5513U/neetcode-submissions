class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }

        // very very good intuition here
        // let's take an example:
        // 10 -> 1 0 1 0
        // 10 >> 1 will be 1 0 1 which is 5
        // We would already know the ans for 5 -> 2
        // So we get 2 for 10 also
        // Let's take odd
        // 11 -> 1 0 1 1
        // 11 >> 1 will be 1 0 1 which is 5
        // We would already know the ans for 5 -> 2
        // So we get 2 + (11 & 1) which is 3
        return ans;
    }
};
