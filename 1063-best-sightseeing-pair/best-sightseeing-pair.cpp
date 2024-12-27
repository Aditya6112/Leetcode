class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>preMaxi;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            maxi=max(values[i]+i,maxi);
            preMaxi.push_back(maxi);
        }

        int ans=INT_MIN;
        for(int j=1;j<n;j++){
            int x=values[j]-j;
            ans=max(ans,x+preMaxi[j-1]);
        }
        return ans;
    }
};