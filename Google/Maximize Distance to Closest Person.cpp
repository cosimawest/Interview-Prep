class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDistance = 0;
        
        // find closest person from first seat        
        for(int i = 0; seats[i] == 0; i++) {
            maxDistance = i + 1; 
        }
        
        // then pick up from there and find largest set of zeros;
        
        for(int i = maxDistance, count = 0; i < seats.size(); i++) {
            if(seats[i] == 0) count++;
            else {
                maxDistance = max(maxDistance, (count/2 + count%2));
                count = 0;
            }
            
            if(i == (seats.size() - 1) && seats[i] == 0) maxDistance = max(maxDistance, count);
        }
        
        return maxDistance;
    }
};
