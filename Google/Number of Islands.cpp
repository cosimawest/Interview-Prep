class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // everytime i hit a 1, turn all of it's adjacent 1 tiles into 0, and
        // all their adjacent 1 tiles into 0
        // this will create pretty much a minesweeper exposure effect
        // plus you can't get confused about islands you come across after bc any 1
        // left on the board didn't belong to the erased islands
        
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    eraseIslands(grid, i , j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        
        if(i == m || i < 0 || j == n || j < 0 || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
        
        return;
    }
};
