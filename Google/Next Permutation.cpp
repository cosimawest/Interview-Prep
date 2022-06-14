class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // got from right until nums[i] > nums[i-1]
        // swap all elements from that index to the end
        
        // literally don't even understand this problem lol i hate permutations
        
        // edit: I understand now, and even figured this solution out without looking!! I'm so smart
        // I was gonna say tho, to sort every element after finding arr[i] > arr[i-1], but if that's
        // the first occurance of that, then I just need to reverse their succeding order since it
        // should already be decending
        
        int i = nums.size() - 1, k = i;
        
        // trying to find the first place starting on the right, where the elements start to decrease
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        
        // i is now the place to the right of the first decreasing number
        // all elements from i to the end are in decending order
        
        
        
        // swapping all elements from i to the end of the array
        for(int j = i; j < k; j++, k--) {
            swap(nums[k], nums[j]);
        }
        
        // i is still that first partition point, but the number has changed
        
        // here we swap the point to the left of the partition point with the first number larger
        // than it
        //
        // this number will always exist since the requirement for finding the partition point was
        // for the number to the left of it to be smaller
        if(i > 0) {
            k = i--;
            while(nums[k] <= nums[i]) k++;     

            // k is now the other partition

            swap(nums[i], nums[k]);
        } 
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        
        a = b;
        b = temp;
    }
};
