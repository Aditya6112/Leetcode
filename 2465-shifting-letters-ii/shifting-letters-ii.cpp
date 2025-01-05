class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //difference array approach we will use here
        vector<char>alphabets;
        for(char ch='a';ch<='z';ch++){
            alphabets.push_back(ch);
        }
        vector<int>arr(s.size(),0);//to store the difference array how much shift each char required;

        for(auto shift:shifts){
            int start=shift[0];
            int end=shift[1];
            int dir=shift[2];
            if(dir==1){
                arr[start]+=1;
                if(end+1<s.size())arr[end+1]-=1;
            }else{
                arr[start]-=1;
                if(end+1<s.size())arr[end+1]+=1;
            }
        }
        int prev=arr[0];
        for(int i=1;i<arr.size();i++){
            prev+=arr[i];
            arr[i]=prev;
        }
        string ans="";
        for(int i=0;i<arr.size();i++){
            int pos=(s[i]-'a')+arr[i];
            if(pos>=26 || pos<=-1)pos%=26;
            if(pos<=-1)pos+=26;
            char ch=alphabets[pos];
            ans+=ch;
        }
        return ans;
    }
};