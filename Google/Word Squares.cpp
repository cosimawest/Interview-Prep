class Solution {
public:
    // global variable so that we can manipulate the vector wo adding another parameter to the recursive function
    vector<vector<string>> res;
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<string>> map;
        
        // we need to make a hashmap of vectors w the key being their prefix
        // w, wa, wal, wall
        // a, ar, are, area
        // l, le, lea, lead
        // l, la, lad, lady
        // words sharing the same prefix will be in the vector together (ex: l => {lead, lady})
        for(auto word : words) {
            string temp = "";
            for(int i = 0; i < word.size(); i++) {
                temp.push_back(word[i]);
                map[temp].push_back(word);
            }
        }
        
        vector<string> e = {};
        for(auto word : words)
            findWordSquare(word, word, 0, map, e);
        
        return res;      
    }
    
    void findWordSquare(string word, string c, int i, unordered_map<string, vector<string>>& map, vector<string> t) {
        // function will only be called on valid inputs so we can push right away
        t.push_back(c);
        
        // sucess case: i will only get to this requirement
        // if this function was called enough times
        // could have also gone with t.size(), but that takes more time than comparing i's value
        if(i >= word.size()-1) {
            res.push_back(t);
            return;
        }
        
        // we're checking if a word would make a valid word square as we go so reduce runtime
        // to do that, we need to calculate the prefix that the next word needs to have to create a valid
        // word square. This being, if this is the 3rd word added to the square, the 3rd char of each 
        // previous word needs to be the prefix of this next word
        string prefix = "";
        if(i+1 < word.size()) 
            for(auto s : t) 
                prefix.push_back(s[i+1]);
        
        // we check if there are any words with this prefix, and return if not
        if(map[prefix].empty()) 
            return;

        // if there are words with this prefix, run through all of them
        for(auto e : map[prefix]) 
            findWordSquare(word, e, i+1, map, t);
        
        return;

    }
};

