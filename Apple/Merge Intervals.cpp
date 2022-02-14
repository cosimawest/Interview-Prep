class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        
        // sort by first element of each nested vector
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            // always check from back of res, since it should always be the largest start
            if(res.back().back() < intervals[i].front()) res.push_back(intervals[i]);
            else res.back() = {res.back().front(), max(res.back().back(), intervals[i].back())};
        }
     
        return res;
    }
};

/*

hashmap of intervals

interval if 
    firstX <= firstY && lastX >= firstY
    OR
    firstX <= lastY && lastX >= lastY
    
    adding intervals to hashmap woun't be more efficient than a list bc i can't access direct items i have to iterate
    
    also then I would iterate multiple times to catch leftovers
    
    
    Rules:
        -Is interval if (see above)
        -
        
    idkkkkkkkkkkk


*/
