class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN;
        priority_queue<int>pq;

        for(int j=1;j<n;j++){
            pq.push(values[j-1]+(j-1));
            int x=values[j]-j;
            ans=max(ans,x+pq.top());
        }
        return ans;
    }
};