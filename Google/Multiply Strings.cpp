class Solution {
public:
    string multiply(string num1, string num2) {   
        if(num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        string sum;
        
        // num2 with the j pointer is acting like the top number in a hand written multiplation problem
        // 
        //  ###  <--num2
        //   ##  <--num1
        // x___
        
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                res[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                res[i+j] += res[i+j+1]/10;
                res[i+j+1] %= 10;
            }
        }
        
        int i = 0;
        while(res[i] == 0) i++;
        while(i < res.size()) sum+=to_string(res[i++]);
        
        return sum;
    }
};
