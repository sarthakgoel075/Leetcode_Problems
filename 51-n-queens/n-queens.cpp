class Solution {
public:
    int size;
    
    void fun(int i, vector<int>& rowcount, vector<int>& colcount, unordered_map<int, int>& mainDiag, unordered_map<int, int>& antiDiag, vector<string>& curr, vector<vector<string>>& ans) {
        if (i == size) {  // Base case: all rows are filled
            ans.push_back(curr);
            return;
        }
        
        for (int j = 0; j < size; j++) {
            if (rowcount[i] == 0 && colcount[j] == 0 && mainDiag[i - j] == 0 && antiDiag[i + j] == 0) {
                curr[i][j] = 'Q';
                rowcount[i] = 1;
                colcount[j] = 1;
                mainDiag[i - j] = 1;
                antiDiag[i + j] = 1;
                
                fun(i + 1, rowcount, colcount, mainDiag, antiDiag, curr, ans);
                
                curr[i][j] = '.';
                rowcount[i] = 0;
                colcount[j] = 0;
                mainDiag[i - j] = 0;
                antiDiag[i + j] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<vector<string>> ans;
        unordered_map<int, int> mainDiag, antiDiag;
        vector<int> rowcount(n, 0), colcount(n, 0);
        vector<string> curr(n, string(n, '.')); // Initialize empty board
        
        fun(0, rowcount, colcount, mainDiag, antiDiag, curr, ans);
        return ans;
    }
};
