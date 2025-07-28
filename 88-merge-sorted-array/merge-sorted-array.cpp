class Solution {
public:
    void mergeing(vector<int>& arr,int left,int mid,int right){
        vector<int>final_arr;
        int i=left;
        int j=mid+1;
        while(i<=mid && j<=right){
            if(arr[i]<arr[j]){
                final_arr.push_back(arr[i]);
                i++;
            }else{
                final_arr.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            final_arr.push_back(arr[i]);
            i++;
        }
        while(j<=right){
            final_arr.push_back(arr[j]);
            j++;
        }
        for(int k=0;k<final_arr.size();k++){
            arr[left + k]=final_arr[k];
        }
    }
    void mergeSort(vector<int>& arr,int start,int end){
        if(start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        mergeing(arr,start,mid,end);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        mergeSort(nums1,0,m+n-1);
    }
};