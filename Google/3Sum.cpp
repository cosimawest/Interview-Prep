class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 3) return {};
        if(nums[0] > 0) return {};
        
        unordered_map<int, int> poss;
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++) {
            poss[nums[i]] = i;
        }

        
        int j = 0;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) return res;
            
            for(int j = i + 1; j < nums.size(); j++) {
                int expected = -1 * (nums[i] + nums[j]);
                
                if(poss.count(expected) && poss[expected] > j) res.push_back({nums[i], nums[j], expected});
                
                j = poss[nums[j]];
            }
            i = poss[nums[i]];
        }
        return res;
    }
};
