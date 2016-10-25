class Solution {
private:
    bool isDigit(char c){return c>='0' && c<='9';}
public:
    string decodeString(string s) {
        stack<int> counts_stk;
        stack<string> str_stk;
        int cnt=0;
        string str="";
        string res="";
        for(int i=0; i < s.size(); i++){
            if( isDigit(s[i]) ){
                cnt = 10*cnt + s[i]-'0';
            }else if( '[' == s[i]){
                counts_stk.push(cnt);
                cnt = 0;
                str_stk.push(res);
                res.clear();
            }else if( ']' == s[i]){
                int k=counts_stk.top();
                for(int j=0;j<k;j++)    str_stk.top() += res;
                res = str_stk.top();
                str_stk.pop();
                counts_stk.pop();
            }else   res+=s[i];
        }
        return str_stk.empty()? res:str_stk.top();
    }
};