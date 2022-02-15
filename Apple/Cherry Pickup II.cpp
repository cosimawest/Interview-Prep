class Solution {
public:
    int dp[79][79][79];
    bool flag = false;
    
    int cherryPickup(vector<vector<int>>& grid, int idx = 0, int j1 = 0, int j2 = 0) {
        /* notes:
        idx = current row level
        j1 = column robot1 is at
        j2 = colmn robot2 is at
        */
        
        if(!flag) {
            // for initial iteration;
            idx = 0;
            j1 = 0;
            j2 = grid[0].size() - 1;
            memset(dp, -1, sizeof(dp));
            flag = true;
        }
        
        if(idx == grid.size()) // current row is out of bounds
            return 0;
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) // robot is out of bounds
            return INT_MIN;
        
        if(dp[idx][j1][j2] != -1)
            return dp[idx][j1][j2];
        
        int ans = INT_MIN;
        int curr = grid[idx][j1] + grid[idx][j2];
        if(j1 == j2) curr -= grid[idx][j1];
        
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1, j2));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1, j2 + 1));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1, j2 - 1));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 + 1, j2));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 + 1, j2 + 1));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 + 1, j2 - 1));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 - 1, j2));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 - 1, j2 + 1));
        ans = max(ans, curr + cherryPickup(grid, idx + 1, j1 - 1, j2 - 1));
        
        return dp[idx][j1][j2] = ans;
    }
};
