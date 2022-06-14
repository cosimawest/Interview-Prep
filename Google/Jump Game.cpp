class Solution {
public:
    bool canJump(vector<int>& nums) {
        // always update with the furthest distance you can go
        // if index > reach, exit early bc that means we can never get to that index
        
        int size = nums.size(), i = 0;
        
        for(int reach = 0; i < size && i <= reach; i++) {
            reach = max(i + nums[i], reach);
        }
        
        return i == size;
    }
};
