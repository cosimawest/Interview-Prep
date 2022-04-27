class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // hashmap length shows distinct characters
        
        // cycle through adding one at a time untill distinict characters exceeds k
        // then sliding window
        // list for front most character (or just currFront int)
        // hash[i]-- curr++
        
        unordered_map<char, int> hash;
        int curr = 0;
        int longest = 0;
        int currL = 0;
        
        for(int i = 0; i <= s.size(); i++) {              
            if(hash.size() > k) {
                cout << hash[s[curr]] << endl;
                hash[s[curr]]--;
                if(hash[s[curr]] == 0)
                    hash.erase(s[curr]);
                curr++;
                currL--;
            } else {
                longest = max(currL, longest);
            }
            
            hash[s[i]]++;
            currL++;
            
        }
        
        return longest;
    }
};
