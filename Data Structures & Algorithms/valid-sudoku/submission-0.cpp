class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // m x m matrix
        int m = (int)board.size();
        int boxes = m / 3;
        
        unordered_map<int, unordered_map<int, int>> freq_box;

        // check rows and cols and boxes
        for (int i = 0; i < m; ++i) { // rows / cols
            vector<int> freq_row(9, 0);
            vector<int> freq_col(9, 0);
            int num;
            for (int j = 0; j < m; ++j) { // cols / rows
                num = board[i][j] - '1';
                // if char == '.' num < 0
                if (num >= 0 && freq_row[num]++) return false; // invalid row

                num = board[j][i] - '1';
                if (num >= 0 && freq_col[num]++) return false; // invalid col

                num = board[i][j] - '1';
                int box_id = j / 3 + boxes * (i / 3);
                if (num >= 0 && freq_box[box_id][num]++) return false; // invalid box
            }
        }

        return true;

    }
};
