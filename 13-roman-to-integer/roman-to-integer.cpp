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

        int sum=0;
        int i=0;
        while(i<s.size()){
            char a=s[i];
            char b=s[i+1];
            string temp="";
            temp+=a;
            temp+=b;
            if(mp2.find(temp)!=mp2.end()){
                sum+=mp2[temp];
                i+=2;
            }else{
                sum+=mp[a];
                i++;
                // if(i==s.size()-1){
                //     sum+=mp[b];
                // }
            }
        }
        return sum;
    }
};