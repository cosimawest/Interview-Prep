class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        
        for(auto word : words) {
            int i, j;
            for(i = 0, j = 0; j < s.size(); j++) {
                if(word[i] == s[j]) i++;
                else if(j > 0 && s[j] == s[j-1] && j + 1 < s.size() && s[j] == s[j+1]) j++;
                else if(!(j > 1 && s[j] == s[j-1] && s[j] == s[j - 2])) break;
            }    
            if(i == word.size() && j == s.size()) res++;
        }
        return res;
    }
};
