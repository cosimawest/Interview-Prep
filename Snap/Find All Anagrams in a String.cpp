class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};

        vector<int> res;
        vector<int> pHash(26, 0);
        vector<int> window(26, 0);
        
        for(int i = 0; i < p.size(); i++) {
            pHash[p[i] - 'a']++; // frequency chart of p
            window[s[i] - 'a']++; // frequency chart of first p.size chars of s
        }
        
        if(pHash == window) res.push_back(0);

        for(int i = p.size(); i < s.size(); i++) {
            window[s[i - p.size()] - 'a']--; // decrement frequency of first char of s
            window[s[i] - 'a']++; // increment frequency of next char of s
            
            if(pHash == window) res.push_back(i - p.size() + 1); // check if anagram
        }
        
        return res;
    }
};
