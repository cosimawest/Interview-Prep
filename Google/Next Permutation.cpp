class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // got from right until nums[i] > nums[i-1]
        // swap all elements from that index to the end
        
        // literally don't even understand this problem lol i hate permutations
        
        // edit: I understand now, and even figured this solution out without looking!! I'm so smart
        
        
//         int i = nums.size() - 1, k = i, tmp;
        
//         while(i > 0 && nums[i-1] >= nums[i]) 
//             i--;
        
//         for(int j = i; j < k; j++, k--)
//             tmp = nums[j], nums[j] = nums[k], nums[k] = tmp;
        
//         if(i > 0) {
//             k = i--;
//             while (nums[k] <= nums[i])
//                 k++;
//             tmp = nums[i], nums[i] = nums[k], nums[k] = tmp;
//         }
        
        
        

    }
};
