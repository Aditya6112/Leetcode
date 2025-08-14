class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                reverse(temp.begin(),temp.end());
                if(temp!="")ans+=temp+' ';
                else ans+=temp;
                temp="";
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp+' ';
        int i=ans.size()-1;
        while(i>=0){
            if(ans[i]==' '){
                i--;
            }else{
                break;
            }
        }
        return ans.substr(0,i+1);
    }
};