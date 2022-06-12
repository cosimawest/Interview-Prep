class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            fix one int in nums
            
            go to next one and search remaining nums for the corresponding num
        */
        
        vector<vector<int>> res;
        unordered_map<int, int> map;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) break;
            int a = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                int c = -1*(a + b);
                if(map.count(c) && map[c] > j) res.push_back({a,b,c});
                j = map[nums[j]];
            }
            i = map[nums[i]];
        }
        
        return res;
    }
};
