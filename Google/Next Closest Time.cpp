class Solution {
public:
    string nextClosestTime(string time) {
        set<char> sorted;
        
        for(auto i : time) {
            if(i == ':') continue;
            
            sorted.insert(i);
        }
        
        string res = time;
        
        
        for(int i = time.size()-1; i >= 0; i--) {
            if(time[i] == ':' ) continue;
            
            auto it = sorted.find(time[i]);
            
            // if not largest num
            if(*it != *sorted.rbegin()) {
                // it++ is next largest num, replace res[i] with it
                it++;
                res[i] = *it;
                // check if valid time
                if((i>=3 && stoi(res.substr(3,2))<60) || (i<2&&stoi(res.substr(0,2))<24)) {
                    return res;
                }
            }
            // replaces res[i] with smallest available num
            res[i] = *sorted.begin();
        }
        return res;
    }
};
