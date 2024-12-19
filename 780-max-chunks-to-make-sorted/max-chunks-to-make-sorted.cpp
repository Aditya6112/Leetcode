class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>prefixMax,suffixMin;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            prefixMax.push_back(maxi);
        }
        for(int i=arr.size()-1;i>=0;i--){
            mini=min(mini,arr[i]);
            suffixMin.push_back(mini);
        }
        reverse(suffixMin.begin(),suffixMin.end());

        int chunk=0;
        for(int i=0;i<arr.size();i++){
            int preMax=(i-1)>=0 ? prefixMax[i-1] : -1;
            int suffMin=suffixMin[i];
            if(preMax<suffMin)chunk++;
        }
        return chunk;
    }

};