class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // AHHH IM A GENIUS HAFDHADK
        
        unordered_map<char, int> map;
                
        int start=0, end=0, res=INT_MIN;
        
        while(end < s.size()){
            map[s[end++]]++;
                
            while(map.size() > 2)
                if(map[s[start++]]-- == 1) map.erase(s[start-1]);
            
            res = max(res, end-start);
        }
        
        return res;
    }
};
