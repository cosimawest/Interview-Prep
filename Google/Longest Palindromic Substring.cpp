// two pointer solution
class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0, n = s.size();
        string res = "";
        
        while(l < n) {
            string candidate = "";
            
            while(s[l] == s[r]) {
                candidate.push_back(s[l]);
                l++;
            }
            while(r > 0 && l < s.size() && s[l] == s[r-1]) {
                string temp = candidate;
                candidate = s[l] + temp + s[l];
                l++, r--;
            }
            if(candidate.size() > res.size()) res = candidate;
            if(n-(1+((l+r)/2)) <= res.size()/2) break;
            r=1+((l+r)/2);
            l=r;
        }
        
        return res;
    }
};

// dp solution
