class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res;
                
        vector<pair<int,int>> sorted;
        
        for(int i = 0; i < indices.size(); i++) {
            sorted.push_back({indices[i], i});
        }
        sort(sorted.begin(), sorted.end());
        
        // the above code is for if the indices are out of order
        // since my solution operates in order to avoid having to use insert and push_back instead!

        // NOTE: sorted[i].second is used for identifying the actual positions of sources and targets
        
        // add s[j] to res if j < indices[i] || i > indices.size() THEN augment j by 1
        // else add targets[i] to res if targets[i] match s[j->n] THEN augment j by sources[i].size()
        // else (if target[i] doesnt match next n chars in s) continue
        
        for(int i = 0, j = 0; j < s.size();) {
            int actual;
            if(i < indices.size()) actual = sorted[i].second;
            
            if(i >= indices.size() || j < sorted[i].first)
                res.push_back(s[j++]);
            else if(sources[actual] == s.substr(j, sources[actual].size())) {
                for(auto c : targets[actual]) res.push_back(c);
                j+=sources[actual].size();
                i++;
            } else i++;
        }
        
        return res;
    }
};
