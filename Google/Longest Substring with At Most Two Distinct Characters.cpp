class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // if i use a count variable then I don't have to use erase
        
        vector<int> map(256, 0);
        
        // iterate through s, have count variable
        // augment s[end] in map (agument count if letter i map was at 0)
        // while count > 2 move start up, decrementing s[start] in map (decrement count if at 0)
        
        // return end-start
        
        int start = 0, end = 0, count = 0, res = 0;
        
        while(end < s.size()) {
            if(map[s[end++]]++ == 0) count++;
            while(count > 2) if(map[s[start++]]-- == 1) count--;
            res = max(res, end-start);
        }
        
        return res;
    }
};
