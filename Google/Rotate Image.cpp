class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // flip the matrix
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i+1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse each row
        for(int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
};
