class Solution {
public:
    string decodeString(string s) {
        //394. Decode String 
        //string ans="";
        string cur="";
        int cnt=0;
        stack<int> repeat;
        stack<string> pre;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                cnt=10*cnt+(s[i]-'0');
            }else if(s[i]!='['&&s[i]!=']'){
                cur+=s[i];
            }else if(s[i]=='['){
                repeat.push(cnt);
                pre.push(cur);
                cnt=0;
                cur="";
            }else if(s[i]==']'){
                string tt="";
                int count=repeat.top();
                repeat.pop();
                while(count-->0){
                    tt+=cur;
                }
                cur=pre.top()+tt;
                pre.pop();
            }
        }
        return cur;
    }
};
