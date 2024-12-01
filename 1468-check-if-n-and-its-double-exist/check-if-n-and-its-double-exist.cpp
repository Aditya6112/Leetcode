class Solution {
public:
    int binarySearch(vector<int>& arr,int t){
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==t){
                return mid;
            }else if(arr[mid]>t){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int target=2*arr[i];
            int idx=binarySearch(arr,target);
            if(idx>=0 && idx!=i){return true;}
        }
        return false;
    }
};