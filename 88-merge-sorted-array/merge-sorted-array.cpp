class Solution {
public:
    void merging(vector<int>& nums,int start,int mid,int end){
        vector<int>temp;
        int i=start,j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<min(nums.size(),temp.size());i++){
            nums[start+i]=temp[i];
        }
    }
    void mergeSort(vector<int>& nums,int start,int end){
        if(start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merging(nums,start,mid,end);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        mergeSort(nums1,0,m+n-1);
    }
};