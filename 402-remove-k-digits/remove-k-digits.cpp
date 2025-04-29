class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>(num[i]-'0') && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            char t=st.top()+'0';
            st.pop();
            ans+=t;
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};