class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // swap i and j of each tile, then reverse the row
        int length = matrix.size();
        
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix, i, j, j, i);
            }
        }
        
        for(int i = 0; i < length; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
    void swap(vector<vector<int>>& matrix, int i, int j, int k, int l) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[k][l];
        matrix[k][l] = temp;
    }
};
