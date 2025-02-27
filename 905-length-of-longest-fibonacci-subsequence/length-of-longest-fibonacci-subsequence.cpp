class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxLen=0;
        unordered_set<int>mpp(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prev=arr[j];
                int curr=arr[i]+arr[j];
                int len=2;
                while(mpp.find(curr)!=mpp.end()){
                    int temp=curr;
                    curr+=prev;
                    prev=temp;
                    maxLen=max(maxLen,++len);
                }
            }
        }
        return maxLen;
    }
};