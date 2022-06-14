class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // go from right until nums[i] > nums[i-1]
        // find the first element from the right that is larger than nums[i-1] (will always be true)
        // swap all elements from that index to the end
        
        // literally don't even understand this problem lol i hate permutations
        
        // edit: I understand now, and even figured this solution out without looking!! I'm so smart
        
        // edit 2: my solution was wrong lol but it honestly wasn't far off
        
        int i = nums.size() - 1, k = i;
        
        // trying to find the first place starting on the right, where the elements start to decrease
        while(i > 0 && nums[i-1] >= nums[i]) 
            i--;
        
        // i is now the place to the right of the first decreasing number
        // all elements from i to the end are in decending order
        
        // here we swap the point to the left of the partition point with the first number larger
        // than it, starting from the right
        //
        // this number will always exist since the requirement for finding the partition point was
        // for the number to the left of it to be smaller
        //
        // the only reason we're not immediately swapping the number left of the partition with the partition
        // number is because there's might be another number in that range that's smaller
        // than the partition number, but larger than the left one. This is because the left number could
        // dropp waaaaay off.
        if(i > 0) {
            while(nums[k] <= nums[i-1]) 
                k--;     
            swap(nums[i-1], nums[k]);
        } 
                
        // swapping all elements from i to the end of the array
        for(int j = nums.size()-1; j > i; j--, i++)
            swap(nums[i], nums[j]);
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
