class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefixSum(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            string str=words[i];
            int size=str.size();
            if((str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u') && 
               (str[size-1]=='a' || str[size-1]=='e' || str[size-1]=='i' || str[size-1]=='o' || str[size-1]=='u')){
                    cnt++;
            }
            prefixSum[i]=cnt;
        }
        vector<int>ans;
        for(auto q:queries){
            int s=q[0];
            int e=q[1];
            if(s==0)ans.push_back(prefixSum[e]);
            else ans.push_back(prefixSum[e]-prefixSum[s-1]);
        }
        return ans;
    }
};