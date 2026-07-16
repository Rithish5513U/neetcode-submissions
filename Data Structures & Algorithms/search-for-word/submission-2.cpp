class Solution {
public:
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string& word){
        if(ind == word.size()) return 1;

        int m = board.size(), n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[ind]) return 0;

        char temp = board[i][j];
        board[i][j] = '*';

        bool f = dfs(i+1, j, ind+1, board, word) || dfs(i-1, j, ind+1, board, word) || dfs(i, j+1, ind+1, board, word) || dfs(i, j-1, ind+1, board, word);

        board[i][j] = temp;
        return f;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        // queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, 0, board, word)) return 1;
            }
        }
        return false;
    }
};
