class Solution {
public:
    int queen[8];
    vector<vector<string>> ans;
    bool check(int row, int col, int n){
        for(int prev_row = 0; prev_row < row; prev_row++){
            int prev_col = queen[prev_row];
            if(prev_col == col || (abs(prev_col-col) == abs(prev_row-row)))
                return 0;
        }
        return 1;
    }
    void rec(int row, int n){
        // base condition
        if(row == n){
            vector<string> temp;
            for(int i = 0; i < n; i++){
                string s = "";
                for(int j = 0; j < n;  j++){
                    if(queen[i] == j)  // queen is in col queen[i] in row i
                        s += 'Q';
                    else
                        s += '.';
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }

        for(int col = 0; col < n; col++){
            if(check(row, col, n)){
                queen[row] = col;
                rec(row+1, n);
                queen[row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        fill(queen, queen + 8, -1);
        rec(0, n);
        return ans;
    }
};
