class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // loop til you find a 0, that will be start
        // loop til you find a 1, that will be end
        // calculate closest distance and compare to current largest closest distance
        // if start = 0 or end = seat.size()-1 distance is not to be halfed when calculating
        
        int res = 0, start = -1, end = -1;
        
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 0) {
                start = i++;
                while(i < seats.size() && seats[i] != 1) i++;
                end = i;
                if(start != 0 && end != seats.size()) res = max(res, (end-(start-1))/2);
                else res = max(res, end-start);
            }
        }
        return res;
    }
};
