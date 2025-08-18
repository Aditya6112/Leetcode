class Solution {
public:
    void merge(vector<int>& nums,int s,int m,int e){
        int i=s;
        int j=m+1;
        vector<int>ans;
        while(i<=m && j<=e){
            if(nums[i]<nums[j]){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            ans.push_back(nums[j]);
            j++;
        }
        for(int k=0;k<=ans.size()-1;k++){
            nums[k+s]=ans[k];
        }
    }
    void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>ans=nums;
        mergeSort(ans,0,ans.size()-1);
        return ans;
    }
};