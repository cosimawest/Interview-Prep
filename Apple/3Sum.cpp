class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size() < 3) return {};
        if(nums[0] > 0) return {};

        vector<vector<int>> result;
        unordered_map<int, int> twoSum;
        
        for(int i = 0; i < nums.size(); i++) {
            twoSum[nums[i]] = i;
        }
        
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) return result;
            
            for(int j = i + 1; j < nums.size(); j++) {
                int expected = -1 * (nums[i] + nums[j]);
                
                if(twoSum.count(expected) && twoSum.find(expected)->second > j)
                    result.push_back({nums[i], nums[j], expected});
                
                j = twoSum.find(nums[j])->second;
            }
            i = twoSum.find(nums[i])->second;
        }
        
        return result;
    }
};
