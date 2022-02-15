class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1) return chars.size();
        
        int pointer = 1;
        int counter = 1;
        char prev = chars[0];
                
        for(int i = 1; i < chars.size(); i++) {
            char curr = chars[i];
            if(curr == prev) 
                counter++;
            else if(counter > 1) {
                for (const auto& d: to_string(counter)) {
                    chars[pointer++] = d;
                }
            } 
            if(curr != prev) {
                chars[pointer] = curr;
                counter = 1;
                pointer++;
            }
            
            prev = curr;
        }
        
        if(counter > 1){
            for (const auto& d: to_string(counter))
                chars[pointer++] = d;
        }
        
        return pointer;
    }
};
