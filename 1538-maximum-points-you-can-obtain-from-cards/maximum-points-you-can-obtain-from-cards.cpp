class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=k-1;
        int j=cardPoints.size()-1;
        int lSum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int rSum=0;
        int ans=lSum;
        
        while(k--){
            lSum-=cardPoints[i];
            rSum+=cardPoints[j];
            ans=max((lSum+rSum),ans);
            i--;
            j--;
        }

        return ans;
    }
};