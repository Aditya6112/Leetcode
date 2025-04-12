class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        stack<char> st;
        for(int i=s.size()-1 ;i>=0 ;i--){
            if(s[i]!=' '){
                st.push(s[i]);
            }else if(s[i]==' ' && !st.empty()){
                while(!st.empty()){
                    temp+=st.top();
                    st.pop();
                }
                ans+=temp;
                ans+=' ';
                temp="";
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        ans+=temp;
        temp="";
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};