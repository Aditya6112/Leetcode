class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int sol=0;
        for(string t:tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int num1=stoi(st.top());
                st.pop();
                int num2=stoi(st.top());
                st.pop();
                int s=0;
                if(t=="+"){
                    s=num1+num2;
                    st.push(to_string(s));
                }else if(t=="-"){
                    s=num2-num1;
                    st.push(to_string(s));
                }else if(t=="*"){
                    s=num1*num2;
                    st.push(to_string(s));
                }else{
                    s=num2/num1;
                    st.push(to_string(s));
                }
            }else{
                st.push(t);
            }
        }
        sol=stoi(st.top());
        st.pop();
        return sol;
    }
};