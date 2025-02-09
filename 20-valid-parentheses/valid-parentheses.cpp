class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)return false;
        stack<char>st;
        for(char ch:s){
            if(ch=='(' || ch=='[' || ch=='{')st.push(ch);
            else{
                if(!st.empty() && ch==')' && st.top()=='('){
                    st.pop();
                }else if(!st.empty() && ch==']' && st.top()=='['){
                    st.pop();
                }else if(!st.empty() && ch=='}' && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};