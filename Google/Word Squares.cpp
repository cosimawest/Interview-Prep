class Solution {
public:
    vector<vector<string>> res;
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        // the issue is that there isn't necesarilly just one answer per word
        // organize words in a set for easier recall
        // or a vector of vectors where the index is the first char of the word
        vector<string> e = {};
        unordered_map<string, vector<string>> map;
        
        // loop through each word in words and call a new function that with the word and index (0)
        // this function returns a vector that we push back
        // we can't just return a vector bc there could be multiple answers
        
        for(auto word : words) {
            string temp = "";
            for(int i = 0; i < word.size(); i++) {
                temp.push_back(word[i]);
                map[temp].push_back(word);
            }
        }
        
        for(auto word : words)
            findWordSquare(word, word, 0, map, e);
        
        return res;
        
        // create vector with first word
        // if the index is the same as the size of the word push_back
        // loop through the vector of vectors for the next letter, calling the recursive function with an 
        // augmented index
        // this will ensure that we don't just stop after adding one element
        // on success, push_back
        // on failure/exhastion return
        // but don't return the recursive call, just call
        // initial call will complete on exhaustion 
        
        // we need to make a hashmap of vectors the the key being their prefix
        // w, wa, wal, wall
        // a, ar, are, area
        // l, le, lea, lead
        // l, la, lad, lady
        

    }
    
    void findWordSquare(string word, string c, int i, unordered_map<string, vector<string>>& map, vector<string> t) {
        //cout << "adding " << c << " and looking for " << word[i+1] << " for " << word << endl;
        //if(c!=word) visited.insert(c);
        t.push_back(c);
        
        if(i >= word.size()-1) {
            res.push_back(t);
            return;
        }
        
        string prefix = "";
        if(i+1 < word.size()) 
            for(auto s : t) prefix.push_back(s[i+1]);
        
        if(map[prefix].empty()) return;

        // take the i th element of every word in t and 
        // the word that starts with those chars is what you're looking for
        for(auto e : map[prefix]) 
            findWordSquare(word, e, i+1, map, t);
        
        return;

    }
};

