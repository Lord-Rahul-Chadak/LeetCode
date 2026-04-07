class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(recurse(board, word, m, n, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool recurse(vector<vector<char>>& board, string& word, int m, int n, int i , int j, int noOfchar){
        if(noOfchar == word.size()){
            return true;
        }

        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[noOfchar]){
            return false;
        }

        char temp = board[i][j];

        board[i][j] = '0';
        bool found = recurse(board, word, m, n, i + 1, j, noOfchar + 1) || recurse(board, word, m, n, i - 1, j, noOfchar + 1) ||         // left or right ka dibba
                     recurse(board, word, m, n, i, j + 1, noOfchar + 1) || recurse(board, word, m, n, i, j - 1, noOfchar + 1);     // upar or niche ka dibba

        board[i][j] = temp;
        return found;
    }
};