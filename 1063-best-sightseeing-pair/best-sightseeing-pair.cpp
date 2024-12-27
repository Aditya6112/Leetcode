class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxi=INT_MIN;
        int ans=INT_MIN;
        
        for(int j=1;j<n;j++){
            maxi=max(maxi,(values[j-1]+(j-1)));
            int x=values[j]-j;
            ans=max(ans,x+maxi);
        }
        return ans;
    }
};