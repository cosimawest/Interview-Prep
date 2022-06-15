class Solution {
public:
    string nextClosestTime(string time) {
        // iterate through time (skip if ":")
        // replace curr digit with next highest digits available
        // check if valid, if so return this time
        // if this is already the highest digit, replace with the lowest digit
        // only increase curr digit iterator if the time is valid
        // return time
        
        set<char> sorted;
        
        for(auto t : time) {
            if(t == ':') continue;
            sorted.insert(t);
        }
        
        for(int i = time.size() - 1; i >= 0; i--) {
            if(time[i] == ':') continue;
            
            auto it = sorted.find(time[i]);
            
            if(*it != *sorted.rbegin()) {
                
                it++;
                time[i] = *it;
                if((time[0] < '2' || (time[0] == '2' && time[1] <= '3')) && time[3] <= '5') return time;
                // if valid, return time
                // if not valid then no other higher number will be valid either. make lowest number
            } 
            // if time[i] is the highest or previously not valid
            time[i] = *sorted.begin();
        }
        
        return time;
    }
};
