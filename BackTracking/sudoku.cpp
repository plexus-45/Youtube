//https://leetcode.com/problems/sudoku-solver/

class Solution {
    public:
        int rowhash[9][9], colhash[9][9], gridhash[3][3][9];

        bool solve(vector<vector<char> > &board, int pos){
            if (pos >= 9*9) {
                return true;
            }
            int row = pos / 9, col = pos % 9;
            if (board[row][col] != '.') {
                return solve(board, pos + 1);
            }
            for (int num = 0; num < 9; num++) {
                if (rowhash[row][num] != 1 && colhash[col][num]!= 1 
                    &&  gridhash[row / 3][col / 3][num] != 1) {
                  
                    board[row][col] = '1' + num;
                    rowhash[row][num] = 1;
                    colhash[col][num] = 1;
                    gridhash[row / 3][col / 3][num] = 1;
                    
                    if (solve(board, pos + 1))
                        return true;
                    
                    // Backtrack
                    board[row][col] = '.';
                    rowhash[row][num] = 0;
                    colhash[col][num] = 0;
                    gridhash[row / 3][col / 3][num] = 0;
                }
            }
            return false;
        }

        void solveSudoku(vector<vector<char> > &board) {
            memset(rowhash, 0, sizeof(rowhash));
            memset(colhash, 0, sizeof(colhash));
            memset(gridhash, 0, sizeof(gridhash));
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '1';
                        rowhash[i][num] = 1;
                        colhash[j][num] = 1;
                        gridhash[i / 3][j / 3][num] = 1;
                    }
                }
            }
            solve(board, 0);
        }
};
