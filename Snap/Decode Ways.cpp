class Solution {
public:
    int numDecodings(string s) {
        // dp will hold all possible combinations at that point in s
        vector<int> dp(s.size() + 1);
        
        // points 0 and 1 will be 1 if valid bc there's one way to combine them individually
        dp[0] = 1;
        dp[1] = s[0] == '0' ?  0 : 1;
        
        for(int i = 2; i <= s.size(); i++) {
            // get prev digit and prev two digits
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigit = stoi(s.substr(i-2, 2));
            
            // if valid, add curr pos value with prev pos value
            if(oneDigit >= 1) {
                dp[i] += dp[i-1];
            }
            
            // if valid, add curr pos value with prev 2 pos value
            if(twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[s.size()];
    }
};
