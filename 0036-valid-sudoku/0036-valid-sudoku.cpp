class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> st;
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {
                if (st.count(board[i][j])) {
                    return false;
                }
                if (board[i][j] != '.')
                    st.insert(board[i][j]);
            }
            st.clear();
        }
        for (int j = 0; j < 9; j++) {

            for (int i = 0; i < 9; i++) {
                if (st.count(board[i][j])) {
                    return false;
                }
                if (board[i][j] != '.')
                    st.insert(board[i][j]);
            }
            st.clear();
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (st.count(board[i][j])) {
                            return false;
                        }
                        if (board[i][j] != '.')
                            st.insert(board[i][j]);
                    }
                }
                st.clear();
            }
        }
        return true;
    }
};