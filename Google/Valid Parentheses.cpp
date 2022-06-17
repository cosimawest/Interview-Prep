class Solution {
public:
    bool isValid(string s) {        
        stack<char> res;
        
        for(auto c : s) {            
            if(isOpen(c)) res.push(c);
            else if(res.empty() || (!res.empty() && !isPartner(res.top(), c))) {
                res.pop();
                return false;
            }
            else res.pop();
        }
        
        if(res.empty()) return true;
        return false;
    }
    
    bool isOpen(char c) {
        if(c == '(' || c == '[' || c == '{') return true;
        else return false;
    }
    
    bool isPartner(char a, char b) {
        if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return true;
        return false;
    }
};
