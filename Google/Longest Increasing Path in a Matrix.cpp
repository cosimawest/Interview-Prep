class Solution {
public:
    int moves[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<int>> dp;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // depth first search with dp
        
        int n = matrix.size(), m = matrix[0].size(), path = 0;
        
        dp.resize(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                path = max(path, go(matrix, i, j));
            }
        }
        
        return path;
    }
    
    int go(vector<vector<int>>& matrix, int i, int j) {
        if(dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        
        for(int k = 0; k < 4; k++) {
            int ni = i + moves[k][0], nj = j + moves[k][1];
            
            if(ni<0||nj<0||ni>=matrix.size()||nj>=matrix[0].size()||matrix[ni][nj]<=matrix[i][j]) continue;
            
            dp[i][j] =  max(dp[i][j], 1 + go(matrix, ni, nj));
        }
        
        return dp[i][j];
    }
};
