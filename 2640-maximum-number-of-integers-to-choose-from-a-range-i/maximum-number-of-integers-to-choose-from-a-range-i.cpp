class Solution {
public:
    bool isBanned(vector<int>& banned,int target){
        int s=0;
        int e=banned.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(banned[mid]==target){
                return true;
            }else if(banned[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0;
        sort(banned.begin(),banned.end());
        for(int i=1;i<=n;i++){
            if(isBanned(banned,i))continue;
            else{
                maxSum-=i;
                if(maxSum>=0){
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};