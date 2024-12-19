class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk=0;
        int cummulative_sum=0;
        int original_sum=0;
        for(int i=0;i<arr.size();i++){
            cummulative_sum+=arr[i];
            original_sum+=i;
            if(original_sum==cummulative_sum)chunk++;
        }
        return chunk;
    }

};