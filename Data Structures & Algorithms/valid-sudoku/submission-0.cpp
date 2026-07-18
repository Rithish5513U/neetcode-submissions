class Solution {
public:
    bool isRow(int row, vector<vector<char>>& board){
        int cnt[10] = {0};
        for(int i = 0; i < 9; i++){
            if(board[row][i] == '.') continue;
            cnt[board[row][i]-'0']++;
            if(cnt[board[row][i]-'0'] > 1) return false;
        }
        return true;
    }
    bool isCol(int col, vector<vector<char>>& board){
        int cnt[10] = {0};
        for(int i = 0; i < 9; i++){
            if(board[i][col] == '.') continue;
            cnt[board[i][col]-'0']++;
            if(cnt[board[i][col]-'0'] > 1) return false;
        }
        return true;
    }
    bool isBox(int row, int col, vector<vector<char>>& board){
        int cnt[10] = {0};
        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                if(board[i][j] == '.') continue;
                cnt[board[i][j]-'0']++;
                if(cnt[board[i][j]-'0'] > 1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        for(int i = 0; i < 9; i++){
            if(!isRow(i, board)) return false;
            if(!isCol(i, board)) return false;
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if(!isBox(i, j, board)){
                    return false;
                }
            }
        }
        return true;
    }
};
