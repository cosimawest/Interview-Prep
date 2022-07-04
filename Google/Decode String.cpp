class Solution {
public:
    string decodeString(string s) {
        // add chars to the string
        // once we hit a number, loop that number of times, adding the group of chars to the string
        // by calling a function that decodes the contents of the brakets, returning a string
        // in that function, call itself if it hits a number
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string s, int& i) {
        cout << "recursion called, word and num reset for now" << endl;
        string word = "";
        int num = 0;
        
        for(; i < s.size(); i++) {
            char cur = s[i];
            cout << word << " " << num << endl;
            if(cur == '[') {
                string toAdd = decode(s, ++i);
                cout << toAdd << " is being added to word" << endl;
                for(; num > 0; num--) word+=toAdd;
                cout << toAdd << " was added, and pos is now " << i << endl;
            }
            else if(cur >= '0' && cur <= '9') {
                cout << "adding " << cur << " to num" << endl;
                num = (num*10) + (cur - '0');
            }
            else if(cur == ']') {
                cout << "reached the end of the bracket. word is " << word << endl;
                return word;
            }
            else {
                cout << "adding " << cur << " to word which is currently " << word << endl;
                word+=cur;
            }
        }
        
        return word;
    }
};
