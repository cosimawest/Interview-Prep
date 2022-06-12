class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // optimized sliding window
        
        // instead of deleting the chars in a set/map til there are no repeats,
        // make hashmap (or 256-length vector) that stores the latest position
        // of each char
        //
        // for each char, we check it's hashmap value
        // if it's value is -1, it isn't repeat and will never be larger than l, we continue
        // if it's value is something else, then it is a repeat. We have to check to see if it's
        // latest position is greater than l. if it is, then that means that 
        
        vector<int> chars(256, -1);
        
        int l = -1, maxL = 0, n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(chars[s[i]] > l) l = chars[s[i]];
            chars[s[i]] = i;
            maxL = max(maxL, i - l);
        }
        
        return maxL;
    }
};
