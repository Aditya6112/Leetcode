class Solution {
public:
    string dTob(int n){
        string ans="";
        int N=n;
        while(N>0){
            char rem=(N%2)+'0';
            ans+=rem;
            N/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool isSet(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')return false;
        }
        return true;
    }
    int smallestNumber(int n) {
        if(isSet(dTob(n)))return n;
        int num=n;
        while(true){
            if(isSet(dTob(num)))return num;
            num+=1;
        }
        return -1;
    }
};