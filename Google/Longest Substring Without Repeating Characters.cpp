class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();

        unordered_set<char> res;
        
        int maxS = 0;
        int r = 0;
        int l = 0;
        
        while(r < s.size()) {
            if(res.count(s[r]) == 0) {
                res.insert(s[r]);
                maxS = max(maxS, (int)res.size());
                r++;
            } else {
                res.erase(s[l]);
                l++;
            }
        }
        
        return maxS;
    }
};
