#include <stack>
class Solution {
public:
    string decodeString(string s) {
        stack<string> S;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==']')
            {
                string str = "";
                while(S.top()[0]!='[')
                {
                    str = S.top() + str;
                    S.pop();
                }

                S.pop();

                string num = "";
                while(!S.empty() && S.top()[0]>='0' && S.top()[0]<='9')
                {
                    num = S.top() + num;
                    S.pop();
                }

                string strs = "";
                for (int j=0;j<stoi(num);j++)
                    strs += str;
                
                S.push(strs);
            }
            else
            {
                string str = "";
                str += s[i];
                S.push(str);
            }
        }

        string ans = "";
        while(!S.empty()){
            ans = S.top() + ans;
            S.pop();
        }
        return ans;
    }
};
