int static t[501][501];
class Solution {
public:
    int lcs(string& s1,string& s2,int n,int m){
        if (n == 0) return m;
        if (m == 0) return n;
        if(t[n][m]!=-1)return t[n][m];
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=lcs(s1,s2,n-1,m-1);
        }
        int insert=1+lcs(s1,s2,n,m-1);
        int del=1+lcs(s1,s2,n-1,m);
        int replace=1+lcs(s1,s2,n-1,m-1);
        return t[n][m]=min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int n=word1.size();
        int m=word2.size();
        return lcs(word1,word2,n,m);
    }
};