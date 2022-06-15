class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // iterate through nums with i pointer for curr num
        // if nums[i] is > lower add lower -> nums[i]-1 (here check also for if lower == nums[i]-1)
        // augment i and make lower = nums[i]+1
        // after loop if lower > higher don't add anything
        
        vector<string> res;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > lower) {
                if(lower == nums[i]-1) res.push_back(to_string(lower));
                else res.push_back(to_string(lower) + "->" + to_string(nums[i]-1));
            } lower = nums[i]+1;
        }
        
        if(lower == upper) res.push_back(to_string(lower));
        if(lower < upper) res.push_back(to_string(lower) + "->" + to_string(upper));
        
        return res;
    }
};
