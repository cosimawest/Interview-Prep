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
class Solution {
public:
    string longestPalindrome(string s) {
        // dp version
        // create bool dp of s.size() x s.size() size
        // make dp[i][i] = t
        // dp[i][i+1] = t if s[i] = s[i+1]
        // then fill the rest of the dp based on if the diagonal line before it is true, and if the ends are
        // the same char
        
        /* dp[0][1] check s[0] == s[1]
           dp[1][4] check s[1] == s[4], dp[2][3] == 1 , d[i++][j--] while i <= j
          a b e e b h
        a 1 0 0 0
        b   1 0 0 1
        e     1 1 0     
        e       1 0 0
        b         1 0
        h           1
        */
        int n = s.size();
        string res = "";
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        
        // build first two lines of dp
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if(i < n-1 && s[i]==s[i+1]) dp[i][i+1] = 1;
        }
        
        for(int i = 2; i < n; i++) {
            for(int j = 0; i+j < n; j++) {
                int r = j, c = i+j;
                dp[j][i+j] = s[r]==s[c] && dp[r+1][c-1];
            }
        }
        
        pair<int, int> maxS = {0,0};
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] && j-i > maxS.second-maxS.first) maxS.first = i, maxS.second = j;
            }
        }
                
        return s.substr(maxS.first, maxS.second-maxS.first+1);
    }
};
