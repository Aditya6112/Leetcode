class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int cnt = 0;
        int maxi = INT_MIN;
        int j=0;
        while(j<n){
            maxi=max(maxi,weight[j]);
            if(weight[j]<maxi){
                cnt++;
                maxi=INT_MIN;
            }
            j++;
        }
        return cnt;
    }
};
