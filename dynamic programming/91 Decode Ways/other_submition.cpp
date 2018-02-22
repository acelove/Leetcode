class Solution {
public:
    int numDecodings(string s) {
        /*
            123
            1 23 -> A V
            12 3 -> L C
            1 2 3 -> A B C      
        */
        vector<int> dp(s.size()+1, 0);
        for (int i = 0; i < s.size(); i++) {
            if ('0' < s[i]) 
                dp[i] += (i>0)?dp[i-1]:1;
            if (i > 0 && s[i-1] > '0' && stoi(s.substr(i-1,2)) <= 26) 
                dp[i] += (i>1)?dp[i-2]:1;
        }
        return dp[s.size()-1];
    }
};
