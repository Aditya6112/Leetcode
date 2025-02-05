class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIdx=0,secondIdx=0;
        if(s1==s2)return true;
        int swaps=0;
        int equal_char=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                swaps++;
                if(swaps>2)return false;
                else if(swaps==1)firstIdx=i;
                else secondIdx=i;
            }
        }
        return s1[firstIdx]==s2[secondIdx] && s1[secondIdx] == s2[firstIdx];
    }
};