class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int nr = matrix.size();
        int nc = matrix[0].size();
        
        // these four variables are for "deleting" rows and columns without the O(n) deletion method
        int rStart = 0;
        int rEnd = nr;
        
        int cStart = 0;
        int cEnd = nc;
                
        vector<int> res;
        
        while(rStart < rEnd && cStart < cEnd) {
            for(i = cStart; i < cEnd; i++) {
                res.push_back(matrix[rStart][i]);
            }
            
            rStart++;
            
            for(i = rStart; i < rEnd; i++) {
                res.push_back(matrix[i][cEnd - 1]);
            }
            
            cEnd--;
            
            if(rStart < rEnd) {
                for(i = cEnd - 1; i >= cStart; i--) {
                    res.push_back(matrix[rEnd - 1][i]);
                }
                rEnd--;
            }
            
            if(cStart < cEnd) {
                for(i = rEnd - 1; i >= rStart; i--) {
                    res.push_back(matrix[i][cStart]);
                }
                cStart++;
            }            
        }
        
        return res;
    }
};
