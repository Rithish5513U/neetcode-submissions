class Solution {
public:
    int sum_of_square(int n){
        int sum = 0;
        while(n){
            int r = n % 10;
            sum += (r * r);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        seen[n] = true;
        while(n != 1){
            n = sum_of_square(n);
            if(seen[n]) return false;
            seen[n] = true;
        }
        return true;
    }
};
