class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        
        if (len==0 || s[0]=='0')
            return 0;
        else if (len==1)
            return 1;
        
        vector<int> ans(s.length(),0);
        
        if (s[len-1] == '0')
            ans[len-1] = 0;
        else
            ans[len-1] = 1;
        
        if (s[len-1]=='0')
        {
            if (s[len-2] <= '2' && s[len-2]>='1')
                ans[len-2] = 1;
            else
                return 0;
        }
        else if (s[len-2]=='1' || (s[len-2]=='2' && s[len-1]<='6' ))
            ans[len-2] = 2;
        else if (s[len-2]=='0')
            ans[len-2] = 0;
        else
            ans[len-2] = 1;
        
        for (int i=len-3;i>=0;i--)
        {
            if (s[i+1] == '0')
            {
                if (s[i]<='2' && s[i]>='1')
                    ans[i] = ans[i+2];
                else
                    return 0;
            }
            else if (s[i]=='1' || (s[i]=='2' && s[i+1]<='6') )
                ans[i] = ans[i+2] + ans[i+1];
            else if (s[i]=='0')
                ans[i] = 0;
            else
                ans[i] = ans[i+1];
        }
        return ans[0];
    }
};
