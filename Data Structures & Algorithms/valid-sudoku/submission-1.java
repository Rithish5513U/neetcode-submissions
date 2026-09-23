class Solution {
    public boolean boxCheck(int row, int col, char[][] board) {
        boolean[] check = new boolean[9];
        for(int i = row; i < row+3; i++){
            for(int c = col; c < col+3; c++){
                if(board[i][c] == '.'){
                    continue;
                }
                if(check[board[i][c]-'0'-1] == true){
                    return false;
                }
                check[board[i][c]-'0'-1] = true;
            }
        }
        return true;
    }
    public boolean rowCheck(int row, char[][] board) {
        boolean[] check = new boolean[9];
        for(int c = 0; c < 9; c++){
            if(board[row][c] == '.'){
                continue;
            }
            if(check[board[row][c]-'0'-1] == true){
                return false;
            }
            check[board[row][c]-'0'-1] = true;
        }
        return true;
    }
    public boolean colCheck(int col, char[][] board) {
        boolean[] check = new boolean[9];
        for(int r = 0; r < 9; r++){
            if(board[r][col] == '.'){
                continue;
            }
            if(check[board[r][col]-'0'-1] == true){
                return false;
            }
            check[board[r][col]-'0'-1] = true;
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        boolean flag = true;
        for(int i = 0; i < 9; i++){
            flag &= rowCheck(i, board);
            flag &= colCheck(i, board);
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                flag &= boxCheck(i, j, board);
            }
        }
        return flag;
    }
}
