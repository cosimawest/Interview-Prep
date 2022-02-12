class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0;
        int high = nums1.size();
        
        int maxLeftX, maxLeftY, minRightX, minRightY;
        
        while(low <= high) {
            int positionX = (low + high) / 2;
            int positionY = (nums1.size() + nums2.size() + 1) / 2 - positionX;
            
            maxLeftX = (positionX == 0) ? INT_MIN : nums1[positionX - 1];
            minRightX = (positionX == nums1.size()) ? INT_MAX : nums1[positionX];
            
            maxLeftY = (positionY == 0) ? INT_MIN : nums2[positionY - 1];
            minRightY = (positionY == nums2.size()) ? INT_MAX : nums2[positionY];
            
            if(maxLeftX > minRightY) high = positionX-1;
            else if(minRightX < maxLeftY) low = positionX+1;
            else break;
        }
        
        if((nums1.size() + nums2.size()) % 2 == 0) //even
            return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY) / 2);
        else
            return (double)max(maxLeftX, maxLeftY);
        
    }
};
