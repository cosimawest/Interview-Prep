class Solution {
public:
    int maxArea(vector<int>& height) {
        // left pointer and right pointer
        // move pointer based on which one is shorter and look for one that's longer
                
        int l = 0, r = height.size()-1;
        
        int maxVol = min(height[l], height[r]) * (r - l);
        
        while(l < r) {
            if(height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
            
            int currVol = min(height[l], height[r]) * (r - l);
            maxVol = max(maxVol, currVol);
        }
        
        return maxVol;
    }
};
