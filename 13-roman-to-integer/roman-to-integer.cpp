class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        unordered_map<string,int>mp2;
        mp['I']=1;
        mp2["IV"]=4;
        mp['V']=5;
        mp2["IX"]=9;
        mp['X']=10;
        mp2["XL"]=40;
        mp['L']=50;
        mp2["XC"]=90;
        mp['C']=100;
        mp2["CD"]=400;
        mp['D']=500;
        mp2["CM"]=900;
        mp['M']=1000;

        int num=0;
        int i=0;
        while(i<s.size()){
            char temp=s[i];
            string t;
            t.push_back(temp);
            if(i+1<s.size() && mp2.find(t+s[i+1])!=mp2.end()){
                cout<<t+s[i+1]<<endl;
                num+=mp2[t+s[i+1]];
                i++;
            }else{
                cout<<temp<<endl;
                num+=mp[temp];
            }
            i++;
        }
        return num;
    }
};