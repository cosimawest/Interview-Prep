class Solution {
public:
    string decodeString(string s) {
        stack<string> str; // holds nested substrings
        stack<int> nums; // holds nested nums
        
        string res; // holds substring
        int num = 0;
        
        for(char c : s) {
            if(isdigit(c)) {
                num = nums * 10 + (c-'0'); // *10 to account for multiple digits
            }
            else if(isalpha(c)) {
                res.push_back(c); // res previously set to "", now stores cur substr
            }
            else if(c == '[') {
                str.push(res); // completed substring to stack
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string temp = res;
                for(int i = 0; i < nums.top() - 1; i++) {
                    res += temp;
                }
                res = str.top() + res;
                str.pop();
                nums.pop();
            }
            
        }
        
        return res;
        
        
        // add if char
        // if num update num
        // if [ push res to string stack, num to num stack, reset res, reset num
        // if ] cycle through stacks, added string stack to front, pop
    }
};


/*

should be done in-place

lol understood the problem wrong

redo

recursive? OMG HARD
stacks? not as elegant, but I can actually figure it out

if you create a string that just stores the substrings you can put them in a stack. Then if you have nested strings, then you can put those in the stack too. You just need to also put the numbers in a different stack, and completely cycle through the stack for each complete bracket.

*/
