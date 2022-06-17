class Solution {
public:
    bool isValid(string s) {
        // add characters in s to stack if it's open
        // if it's closed, compare to top of the stack (must be matching open parenthese)
        // pop stack
        
        stack<char> opens;
        
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{') opens.push(c);
            else {
                if(opens.empty() || !check(opens.top(), c)) return false;
                opens.pop();
            }
        }
        
        if (opens.empty()) return true;
        return false;
    }
    
    bool check(char a, char b) {
        if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') return true;
        return false;
    }
};
