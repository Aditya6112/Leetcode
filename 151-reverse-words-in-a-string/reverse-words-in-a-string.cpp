class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }else if(s[i]==' ' && !temp.empty()){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                if(i!=0){
                    ans+=' ';
                }
                temp="";
                while(i-1>=0 &&  s[i-1]==' '){
                    i--;
                }
            }else{
                continue;
            }
        }
        if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            temp="";
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};